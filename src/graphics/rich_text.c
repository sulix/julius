#include "rich_text.h"

#include "core/calc.h"
#include "core/image.h"
#include "core/image_group.h"
#include "core/locale.h"
#include "core/string.h"
#include "graphics/image.h"
#include "graphics/image_button.h"
#include "graphics/panel.h"
#include "graphics/scrollbar.h"
#include "graphics/window.h"

#define MAX_LINKS 50
#define TEMP_LINE_SIZE 200

static void on_scroll(void);

static scrollbar_type scrollbar = {
    .has_y_margin = 1,
    .on_scroll_callback = on_scroll
};

static struct {
    int message_id;
    int x_min;
    int y_min;
    int x_max;
    int y_max;
} links[MAX_LINKS];

static uint8_t tmp_line[TEMP_LINE_SIZE];

static struct {
    const font_definition *normal_font;
    const font_definition *link_font;
    int line_height;
    int paragraph_indent;

    int x_text;
    int y_text;
    int text_width_blocks;
    int text_height_blocks;
    int text_height_lines;
    int num_lines;
    int max_scroll_position;
    int num_links;
} data;

int rich_text_init(
    const uint8_t *text, int x_text, int y_text, int width_blocks, int height_blocks, int adjust_width_on_no_scroll)
{
    data.x_text = x_text;
    data.y_text = y_text;
    if (!data.num_lines) {
        data.text_height_blocks = height_blocks;
        data.text_height_lines = (height_blocks - 1) * BLOCK_SIZE / data.line_height;
        data.text_width_blocks = width_blocks;

        data.num_lines = rich_text_draw(text,
            data.x_text + 8, data.y_text + 6,
            BLOCK_SIZE * data.text_width_blocks - BLOCK_SIZE, data.text_height_lines, 1);
        scrollbar.x = data.x_text + BLOCK_SIZE * data.text_width_blocks - 1;
        scrollbar.y = data.y_text;
        scrollbar.height = BLOCK_SIZE * data.text_height_blocks;
        scrollbar.elements_in_view = data.text_height_lines;
        scrollbar_init(&scrollbar, scrollbar.scroll_position, data.num_lines);
        if (data.num_lines <= data.text_height_lines && adjust_width_on_no_scroll) {
            data.text_width_blocks += 2;
        }
        scrollbar.scrollable_width = BLOCK_SIZE * data.text_width_blocks;
        window_invalidate();
    }
    return data.text_width_blocks;
}

void rich_text_set_fonts(font_t normal_font, font_t link_font, int line_spacing)
{
    data.normal_font = font_definition_for(normal_font);
    data.link_font = font_definition_for(link_font);
    data.line_height = data.normal_font->line_height + line_spacing;
    data.paragraph_indent = locale_paragraph_indent();
}

void rich_text_reset(int scroll_position)
{
    scrollbar_reset(&scrollbar, scroll_position);
    data.num_lines = 0;
    rich_text_clear_links();
}

void rich_text_clear_links(void)
{
    for (int i = 0; i < MAX_LINKS; i++) {
        links[i].message_id = 0;
        links[i].x_min = 0;
        links[i].x_max = 0;
        links[i].y_min = 0;
        links[i].y_max = 0;
    }
    data.num_links = 0;
}

int rich_text_get_clicked_link(const mouse *m)
{
    if (m->left.went_up) {
        for (int i = 0; i < data.num_links; i++) {
            if (m->x >= links[i].x_min && m->x <= links[i].x_max &&
                m->y >= links[i].y_min && m->y <= links[i].y_max) {
                return links[i].message_id;
            }
        }
    }
    return -1;
}

static void add_link(int message_id, int x_start, int x_end, int y)
{
    if (data.num_links < MAX_LINKS) {
        links[data.num_links].message_id = message_id;
        links[data.num_links].x_min = x_start - 2;
        links[data.num_links].x_max = x_end + 2;
        links[data.num_links].y_min = y - 1;
        links[data.num_links].y_max = y + 13;
        data.num_links++;
    }
}

static int get_word_width(const uint8_t *str, int in_link, int *num_chars)
{
    int width = 0;
    int guard = 0;
    int word_char_seen = 0;
    int start_link = 0;
    *num_chars = 0;
    while (*str && ++guard < 2000) {
        if (*str == '@') {
            str++;
            if (!word_char_seen) {
                if (*str == 'P' || *str == 'L') {
                    *num_chars += 2;
                    width = 0;
                    break;
                } else if (*str == 'G') {
                    // skip graphic
                    *num_chars += 2;
                    while (*str >= '0' && *str <= '9') {
                        str++;
                        (*num_chars)++;
                    }
                    width = 0;
                    break;
                } else {
                    (*num_chars)++;
                    while (*str >= '0' && *str <= '9') {
                        str++;
                        (*num_chars)++;
                    }
                    in_link = 1;
                    start_link = 1;
                }
            }
        }
        int num_bytes = 1;
        if (*str == ' ') {
            if (word_char_seen) {
                break;
            }
            width += 4;
        } else if (*str > ' ') {
            // normal char
            int letter_id = font_letter_id(data.normal_font, str, &num_bytes);
            if (letter_id >= 0) {
                width += 1 + image_letter(letter_id)->original.width;
            }
            word_char_seen = 1;
            if (num_bytes > 1) {
                if (start_link) {
                    // add space before links in multibyte charsets
                    width += 4;
                    start_link = 0;
                }
                if (!in_link) {
                    *num_chars += num_bytes;
                    break;
                }
            }
        }
        str += num_bytes;
        *num_chars += num_bytes;
    }
    return width;
}

static void draw_line(const uint8_t *str, int x, int y, color_t color, int measure_only)
{
    int start_link = 0;
    int num_link_chars = 0;
    while (*str) {
        if (*str == '@') {
            int message_id = string_to_int(++str);
            while (*str >= '0' && *str <= '9') {
                str++;
            }
            int width = get_word_width(str, 1, &num_link_chars);
            add_link(message_id, x, x + width, y);
            start_link = 1;
        }
        if (*str >= ' ') {
            const font_definition *def = data.normal_font;
            if (num_link_chars > 0) {
                def = data.link_font;
            }

            int num_bytes = 1;
            int letter_id = font_letter_id(def, str, &num_bytes);
            if (letter_id < 0) {
                x += def->space_width;
            } else {
                if (num_bytes > 1 && start_link) {
                    // add space before links in multibyte charsets
                    x += def->space_width;
                    start_link = 0;
                }
                const image *img = image_letter(letter_id);
                if (!measure_only) {
                    int height = def->image_y_offset(*str, img->height + img->y_offset, def->line_height);
                    image_draw_letter(def->font, letter_id, x, y - height, color, SCALE_NONE);
                }
                x += img->original.width + def->letter_spacing;
            }
            if (num_link_chars > 0) {
                num_link_chars -= num_bytes;
            }
            str += num_bytes;
        } else {
            str++;
        }
    }
}

static int get_raw_text_width(const uint8_t *str)
{
    int width = 0;
    int guard = 0;
    while (*str && ++guard < 2000) {
        int num_bytes = 1;
        int letter_id = font_letter_id(data.normal_font, str, &num_bytes);
        if (letter_id >= 0) {
            width += 1 + image_letter(letter_id)->original.width;
        }
        str += num_bytes;
    }
    return width;
}

static int draw_text(const uint8_t *text, int x_offset, int y_offset,
                     int box_width, int height_lines, color_t color, int measure_only)
{
    int image_height_lines = 0;
    int image_id = 0;
    int lines_before_image = 0;
    int paragraph = 0;
    int has_more_characters = 1;
    int y = y_offset;
    int guard = 0;
    int line = 0;
    int num_lines = 0;
    while (has_more_characters || image_height_lines) {
        if (++guard >= 1000) {
            break;
        }
        // clear line
        for (int i = 0; i < TEMP_LINE_SIZE; i++) {
            tmp_line[i] = 0;
        }
        int line_index = 0;
        int current_width, x_line_offset;
        current_width = x_line_offset = paragraph ? data.paragraph_indent : 0;
        paragraph = 0;
        while ((has_more_characters || image_height_lines) && current_width < box_width) {
            if (image_height_lines) {
                image_height_lines--;
                break;
            }
            int word_num_chars;
            int word_width = get_word_width(text, 0, &word_num_chars);
            if (word_width >= box_width) {
                // Word too long to fit on a line, so cut it into smaller pieces.
                int can_cut_more = 1;
                while (can_cut_more) {
                    char c = *text;
                    if (c == '@') {
                        break;
                    }
                    text++;
                    tmp_line[line_index++] = c;
                    int temp_width = get_raw_text_width(tmp_line);
                    can_cut_more = (temp_width < box_width);
                }
            }
            current_width += word_width;
            if (current_width >= box_width) {
                if (current_width == 0) {
                    has_more_characters = 0;
                }
            } else {
                for (int i = 0; i < word_num_chars; i++) {
                    char c = *text++;
                    if (c == '@') {
                        if (*text == 'P') {
                            paragraph = 1;
                            text++;
                            current_width = box_width;
                            break;
                        } else if (*text == 'L') {
                            text++;
                            current_width = box_width;
                            break;
                        } else if (*text == 'G') {
                            if (line_index) {
                                num_lines++;
                            }
                            text++; // skip 'G'
                            current_width = box_width;
                            image_id = string_to_int(text);
                            c = *text++;
                            while (c >= '0' && c <= '9') {
                                c = *text++;
                            }
                            image_id += image_group(GROUP_MESSAGE_IMAGES) - 1;
                            image_height_lines = image_get(image_id)->height / data.line_height + 2;
                            if (line > 0) {
                                lines_before_image = 1;
                            }
                            break;
                        }
                    }
                    if (line_index || c != ' ') { // no space at start of line
                        tmp_line[line_index++] = c;
                    }
                }
                if (!*text) {
                    has_more_characters = 0;
                }
            }
        }

        int outside_viewport = 0;
        if (!measure_only) {
            if (line < scrollbar.scroll_position || line >= scrollbar.scroll_position + height_lines) {
                outside_viewport = 1;
            }
        }
        if (!outside_viewport) {
            draw_line(tmp_line, x_line_offset + x_offset, y, color, measure_only);
        }
        if (!measure_only) {
            if (image_id) {
                if (lines_before_image) {
                    lines_before_image--;
                } else {
                    const image *img = image_get(image_id);
                    image_height_lines = img->height / data.line_height + 2;
                    int image_offset_x = x_offset + (box_width - img->original.width) / 2 - 4;
                    if (line < height_lines + scrollbar.scroll_position) {
                        if (line >= scrollbar.scroll_position) {
                            image_draw(image_id, image_offset_x, y + 8, COLOR_MASK_NONE, SCALE_NONE);
                        } else {
                            image_draw(image_id, image_offset_x,
                                y + 8 - data.line_height * (scrollbar.scroll_position - line),
                                COLOR_MASK_NONE, SCALE_NONE);
                        }
                    }
                    image_id = 0;
                }
            }
        }
        line++;
        num_lines++;
        if (!outside_viewport) {
            y += data.line_height;
        }
    }
    return num_lines;
}

int rich_text_draw(const uint8_t *text, int x_offset, int y_offset, int box_width, int height_lines, int measure_only)
{
    return draw_text(text, x_offset, y_offset, box_width, height_lines, 0, measure_only);
}

int rich_text_draw_colored(
    const uint8_t *text, int x_offset, int y_offset, int box_width, int height_lines, color_t color)
{
    return draw_text(text, x_offset, y_offset, box_width, height_lines, color, 0);
}

void rich_text_draw_scrollbar(void)
{
    scrollbar_draw(&scrollbar);
}

int rich_text_handle_mouse(const mouse *m)
{
    return scrollbar_handle_mouse(&scrollbar, m, 1);
}

static void on_scroll(void)
{
    rich_text_clear_links();
    window_invalidate();
}

int rich_text_scroll_position(void)
{
    return scrollbar.scroll_position;
}
