#include "translation/common.h"
#include "translation/translation.h"

static translation_string all_strings[] = {
    {TR_NO_PATCH_TITLE, "未安装1.0.1.0补丁"},
    {TR_NO_PATCH_MESSAGE,
        "《凯撒大帝3》未安装1.0.1.0补丁。"
        "补丁下载链接：\n"
        URL_PATCHES "\n"
        "继续游戏风险自担。"},
    {TR_MISSING_FONTS_TITLE, "缺失字体"},
    {TR_MISSING_FONTS_MESSAGE,
        "《凯撒大帝3》需要额外字体文件。"
        "语言包下载链接：\n"
        URL_PATCHES},
    {TR_NO_EDITOR_TITLE, "未安装地图编辑器"},
    {TR_NO_EDITOR_MESSAGE,
        "《凯撒大帝3》未检测到地图编辑器文件。"
        "地图编辑器下载链接：\n"
        URL_EDITOR},
    {TR_INVALID_LANGUAGE_TITLE, "语言包路径无效"},
    {TR_INVALID_LANGUAGE_MESSAGE,
        "指定路径未检测到有效语言包。"
        "请检视日志查看错误。"},
    {TR_BUILD_ALL_TEMPLES, "全   部"},
    {TR_BUTTON_OK, "确定"},
    {TR_BUTTON_CANCEL, "取消"},
    {TR_BUTTON_RESET_DEFAULTS, "重置默认"},
    {TR_BUTTON_CONFIGURE_HOTKEYS, "热键绑定"},
    {TR_CONFIG_ARE_YOU_SURE, "重置为默认?"},
    {TR_CONFIG_YOU_WILL_LOSE_YOUR_CONFIGS, "你将丢失所有配置信息。"},
    {TR_CONFIG_YOU_WILL_LOSE_YOUR_HOTKEYS, "你将丢失所有热键信息。"},
    {TR_CONFIG_TITLE, "Augustus 配置"},
    {TR_CONFIG_HEADER_GENERAL, "通用设置"},
    {TR_CONFIG_HEADER_UI_CHANGES, "用户界面更变"},
    {TR_CONFIG_HEADER_GAMEPLAY_CHANGES, "游戏难度"},
    {TR_CONFIG_HEADER_CITY_MANAGEMENT_CHANGES, "城市管理"},
    {TR_CONFIG_LANGUAGE_LABEL, "语言包："},
    {TR_CONFIG_LANGUAGE_DEFAULT, "默认"},
    {TR_CONFIG_GAME_SPEED, "游戏速度："},
    {TR_CONFIG_VIDEO, "显示设定"},
    {TR_CONFIG_FULLSCREEN, "全屏"},
    {TR_CONFIG_WINDOWED_RESOLUTION, "窗口化分辨率："},
    {TR_CONFIG_DISPLAY_SCALE, "显示比例："},
    {TR_CONFIG_CURSOR_SCALE, "鼠标比例："},
    {TR_CONFIG_USE_COLOR_CURSORS, "使用彩色鼠标"},
    {TR_CONFIG_AUDIO, "声音选项"},
    {TR_CONFIG_VOLUME, "音量"},
    {TR_CONFIG_ENABLE_AUDIO, "开启声音"},
    {TR_CONFIG_MUSIC, "开启音乐"},
    {TR_CONFIG_SPEECH, "开启语音"},
    {TR_CONFIG_EFFECTS, "开启音效"},
    {TR_CONFIG_CITY_SOUNDS, "开启城市音效"},
    {TR_CONFIG_SCROLL_SPEED, "滚动速度："},
    {TR_CONFIG_SHOW_INTRO_VIDEO, "播放开场动画"},
    {TR_CONFIG_SIDEBAR_INFO, "控制面板更多信息"},
    {TR_CONFIG_SMOOTH_SCROLLING, "平滑视角滚动"},
    {TR_CONFIG_DISABLE_MOUSE_EDGE_SCROLLING, "禁用屏幕边缘滚动地图"},
    {TR_CONFIG_DISABLE_RIGHT_CLICK_MAP_DRAG, "禁用鼠标右键拖动地图"},
    {TR_CONFIG_VISUAL_FEEDBACK_ON_DELETE, "优化清理土地视觉效果"},
    {TR_CONFIG_ALLOW_CYCLING_TEMPLES, "允许连续建造每种神庙"},
    {TR_CONFIG_SHOW_WATER_STRUCTURE_RANGE, "建造时显示贮水池水泉及水井覆盖范围"},
    {TR_CONFIG_SHOW_CONSTRUCTION_SIZE, "显示拖动建设大小"},
    {TR_CONFIG_HIGHLIGHT_LEGIONS, "鼠标悬停时高亮军团"},
    {TR_CONFIG_ROTATE_MANUALLY, "热键可旋转门房与胜利拱门建造方向"},
    {TR_CONFIG_SHOW_MILITARY_SIDEBAR, "显示军队信息侧栏"},
    {TR_CONFIG_FIX_IMMIGRATION_BUG, "修复非常困难不来人BUG"},
    {TR_CONFIG_FIX_100_YEAR_GHOSTS, "修复人口百岁仍占房BUG"},
    {TR_CONFIG_FIX_EDITOR_EVENTS, "修复自定义地图中皇帝更位和生存时间BUG"},
    {TR_CONFIG_DRAW_WALKER_WAYPOINTS, "点击建筑后覆层上勾画出行人路径点"},
    {TR_CONFIG_ENABLE_ZOOM, "开启城市缩放功能（游戏速度可能减慢，需要更多运行内存和显存）"},
    {TR_CONFIG_COMPLETE_RATING_COLUMNS, "修复低目标下无法完成评比任务BUG"},
    {TR_CONFIG_GRANDFESTIVAL, "举办豪华节庆获取神灵更多祝福"},
    {TR_CONFIG_DIFFICULTY, "游戏难度："},
    {TR_CONFIG_GODS_EFFECTS, "开启神灵诅咒/祝福效果"},
    {TR_CONFIG_JEALOUS_GODS, "关闭神灵嫉妒效果"},
    {TR_CONFIG_GLOBAL_LABOUR, "开启全图招工"},
    {TR_CONFIG_SCHOOL_WALKERS, "扩大学校行人路径范围"},
    {TR_CONFIG_RETIRE_AT_60, "市民退休年龄从50延长至60岁"},
    {TR_CONFIG_FIXED_WORKERS, "固定38%的劳工人口"},
    {TR_CONFIG_EXTRA_FORTS, "允许建造4个额外要塞"},
    {TR_CONFIG_WOLVES_BLOCK, "禁止在狼群周边建造"},
    {TR_CONFIG_DYNAMIC_GRANARIES, "禁止未连接主干的谷仓道路"},
    {TR_CONFIG_MORE_STOCKPILE, "住宅可存放更多市场物资"},
    {TR_CONFIG_NO_SUPPLIER_DISTRIBUTION, "取货的市场大妈不分发物资"},
    {TR_CONFIG_IMMEDIATELY_DELETE_BUILDINGS, "秒删建筑"},
    {TR_CONFIG_GETTING_GRANARIES_GO_OFFROAD, "取得货物的谷仓推车工可不走道路运输"},
    {TR_CONFIG_GRANARIES_GET_DOUBLE, "取得货物的谷仓推车工可携运容量翻倍"},
    {TR_CONFIG_ALLOW_EXPORTING_FROM_GRANARIES, "允许商人从谷仓中出口食物"},
    {TR_CONFIG_TOWER_SENTRIES_GO_OFFROAD, "军营无需道路连接至高塔即可提供守卫"},
    {TR_CONFIG_FARMS_DELIVER_CLOSE, "农场和埠头仅向临近谷仓输送食物"},
    {TR_CONFIG_DELIVER_ONLY_TO_ACCEPTING_GRANARIES, "新产食物不会运至取得货物的谷仓"},
    {TR_CONFIG_ALL_HOUSES_MERGE, "所有住宅都会合并"},
    {TR_CONFIG_WINE_COUNTS_IF_OPEN_TRADE_ROUTE, "开启贸易路线算作提供不同种类葡萄酒"},
    {TR_CONFIG_RANDOM_COLLAPSES_TAKE_MONEY, "随机倒塌的黏土坑和铁矿只需耗费金钱自动重建"},
    {TR_CONFIG_MULTIPLE_BARRACKS, "允许建造多个军营" },
    {TR_CONFIG_NOT_ACCEPTING_WAREHOUSES, "仓库和谷仓建造后不接受任何物资"},
    {TR_CONFIG_HOUSES_DONT_EXPAND_INTO_GARDENS, "住宅扩建不会覆盖到花园"},
    {TR_CONFIG_ROAMERS_DONT_SKIP_CORNERS, "间接目标行人不会跳过角落"},
    {TR_CONFIG_ZOOM_COULD_NOT_BE_ENABLED_TITLE, "无法开启城市缩放功能"},
    {TR_CONFIG_ZOOM_COULD_NOT_BE_ENABLED_MESSAGE,
        "你的系统没有足够的显存来开启城市缩放功能。\n"
        "未开启城市缩放功能。"},
    {TR_CONFIG_SHOW_MAX_POSSIBLE_PROSPERITY, "显示当前住房可获得的最高繁荣评比"},
    {TR_HOTKEY_TITLE, "Augustus 热键配置"},
    {TR_HOTKEY_LABEL, "热键"},
    {TR_HOTKEY_ALTERNATIVE_LABEL, "可替代键"},
    {TR_HOTKEY_HEADER_ARROWS, "方向键"},
    {TR_HOTKEY_HEADER_GLOBAL, "全局热键"},
    {TR_HOTKEY_HEADER_CITY, "城市热键"},
    {TR_HOTKEY_HEADER_ADVISORS, "顾问"},
    {TR_HOTKEY_HEADER_OVERLAYS, "覆层"},
    {TR_HOTKEY_HEADER_BOOKMARKS, "城市地图视角标签"},
    {TR_HOTKEY_HEADER_EDITOR, "编辑器"},
    {TR_HOTKEY_HEADER_BUILD, "建造热键"},
    {TR_HOTKEY_ARROW_UP, "上"},
    {TR_HOTKEY_ARROW_DOWN, "下"},
    {TR_HOTKEY_ARROW_LEFT, "左"},
    {TR_HOTKEY_ARROW_RIGHT, "右"},
    {TR_HOTKEY_TOGGLE_FULLSCREEN, "全屏切换"},
    {TR_HOTKEY_CENTER_WINDOW, "中心窗口化"},
    {TR_HOTKEY_RESIZE_TO_640, "重置分辨率至640x480"},
    {TR_HOTKEY_RESIZE_TO_800, "重置分辨率至800x600"},
    {TR_HOTKEY_RESIZE_TO_1024, "重置分辨率至1024x768"},
    {TR_HOTKEY_SAVE_SCREENSHOT, "保存截图"},
    {TR_HOTKEY_SAVE_CITY_SCREENSHOT, "保存城市全景截图"},
    {TR_HOTKEY_BUILD_CLONE, "复制鼠标下的建筑"},
    {TR_HOTKEY_LOAD_FILE, "载入文件"},
    {TR_HOTKEY_SAVE_FILE, "保存文件"},
    {TR_HOTKEY_INCREASE_GAME_SPEED, "加快游戏速度"},
    {TR_HOTKEY_DECREASE_GAME_SPEED, "减慢游戏速度"},
    {TR_HOTKEY_TOGGLE_PAUSE, "暂停切换"},
    {TR_HOTKEY_CYCLE_LEGION, "切换各军团所在视角"},
    {TR_HOTKEY_ROTATE_MAP_LEFT, "顺时针旋转地图视角"},
    {TR_HOTKEY_ROTATE_MAP_RIGHT, "逆时针旋转地图视角"},
    {TR_HOTKEY_SHOW_ADVISOR_LABOR, "劳工顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_MILITARY, "军事顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_IMPERIAL, "皇帝顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_RATINGS, "评比顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_TRADE, "贸易顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_POPULATION, "人口顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_HEALTH, "健康顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_EDUCATION, "教育顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_ENTERTAINMENT, "娱乐顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_RELIGION, "宗教顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_FINANCIAL, "财政顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_CHIEF, "首席顾问"},
    {TR_HOTKEY_SHOW_ADVISOR_HOUSING, "住房顾问"},
    {TR_HOTKEY_TOGGLE_OVERLAY, "当前覆层视角切换"},
    {TR_HOTKEY_SHOW_OVERLAY_RELATIVE, "显示相关覆层"},
    {TR_HOTKEY_SHOW_OVERLAY_WATER, "显示供水覆层"},
    {TR_HOTKEY_SHOW_OVERLAY_FIRE, "显示火灾覆层"},
    {TR_HOTKEY_SHOW_OVERLAY_DAMAGE, "显示损坏覆层"},
    {TR_HOTKEY_SHOW_OVERLAY_CRIME, "显示犯罪覆层"},
    {TR_HOTKEY_ROTATE_BUILDING, "建造正转向"},
    {TR_HOTKEY_ROTATE_BUILDING_BACK, "建造逆转向"},
    {TR_HOTKEY_SHOW_OVERLAY_PROBLEMS, "显示问题覆层"},
    {TR_HOTKEY_GO_TO_BOOKMARK_1, "前往视角标签 1"},
    {TR_HOTKEY_GO_TO_BOOKMARK_2, "前往视角标签 2"},
    {TR_HOTKEY_GO_TO_BOOKMARK_3, "前往视角标签 3"},
    {TR_HOTKEY_GO_TO_BOOKMARK_4, "前往视角标签 4"},
    {TR_HOTKEY_SET_BOOKMARK_1, "设定视角标签 1"},
    {TR_HOTKEY_SET_BOOKMARK_2, "设定视角标签 2"},
    {TR_HOTKEY_SET_BOOKMARK_3, "设定视角标签 3"},
    {TR_HOTKEY_SET_BOOKMARK_4, "设定视角标签 4"},
    {TR_HOTKEY_EDITOR_TOGGLE_BATTLE_INFO, "战斗信息切换"},
    {TR_HOTKEY_EDIT_TITLE, "按下新热键"},
    {TR_BUILDING_ROADBLOCK, "路   障"},
    {TR_BUILDING_ROADBLOCK_DESC, "路障可拦住四处游走的行人。"},
    {TR_BUILDING_ARCHITECT_GUILD, "建筑师协会" },
    {TR_BUILDING_ARCHITECT_GUILD_DESC, "建筑师们在此不辞辛劳地为罗马的荣耀建造纪念碑。" },
    {TR_BUILDING_GRAND_TEMPLE_ADD_MODULE, "授予神庙名号" },
    {TR_BUILDING_GRAND_TEMPLE_CERES, "塞丽丝宏伟神庙（农业之神）" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE, "纳普敦宏伟神庙（海洋之神）" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY, "莫丘里宏伟神庙（商业之神）" },
    {TR_BUILDING_GRAND_TEMPLE_MARS, "马尔斯宏伟神庙（战争之神）" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS, "维纳斯宏伟神庙（爱情之神）" },
    {TR_BUILDING_PANTHEON, "万 神 殿" },
    {TR_BUILDING_GRAND_TEMPLE_CERES_DESC, "塞丽丝宏伟神庙（农业之神）" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC, "纳普敦宏伟神庙（海洋之神）" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC, "莫丘里宏伟神庙（商业之神）" },
    {TR_BUILDING_GRAND_TEMPLE_MARS_DESC, "马尔斯宏伟神庙（战争之神）" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS_DESC, "维纳斯宏伟神庙（爱情之神）" },
    {TR_BUILDING_PANTHEON_DESC, "万神殿" },
    {TR_BUILDING_GRAND_TEMPLE_CERES_BONUS_DESC, "农场推车工移动速度提高50%。" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_BONUS_DESC, "水泉和水井范围+1，贮水池范围+2，供水服务所需劳工降低50%，商船只行驶速度提高25%。" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_BONUS_DESC, "陆地商人和海上商船携货量提高50%，陆地商人移动速度提高25%。" },
    {TR_BUILDING_GRAND_TEMPLE_MARS_BONUS_DESC, "可像军营一样训练士兵，可建造额外四座要塞。" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS_BONUS_DESC, "城市花园、雕像及神庙随着美化程度的提高而发光，并赋予更高地区满意度。住宅可存放更多物资且退化速度更慢。" },
    {TR_BUILDING_PANTHEON_BONUS_DESC, "可供奉所有神灵，且能举行年度节庆，宗教和文化建筑维护费降低25%。" }, // Note to translators: This one changed from the previous version, please update.
    {TR_BUILDING_GRAND_TEMPLE_CERES_MODULE_1_DESC, "祭司能降低食物消耗20%。" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_MODULE_1_DESC, "神庙可为马术场生产战车。" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_MODULE_1_DESC, "祭司能降低陶器和家具消耗20%。" },
    {TR_BUILDING_GRAND_TEMPLE_MARS_MODULE_1_DESC, "神庙可根据自己覆盖的住宅数量生产相应数量的食物，并运送至军粮站。要塞维护费降低25%。" }, // Note to translators: This one changed from the previous version, please update.
    {TR_BUILDING_GRAND_TEMPLE_VENUS_MODULE_1_DESC, "宏伟神庙可根据接触到维纳斯神庙的城市人口量生产出相应数量的葡萄酒，神庙中生产存放好的葡萄酒经祭司分发至住宅和酒馆。" },
    {TR_BUILDING_GRAND_TEMPLE_CERES_MODULE_2_DESC, "祭司能从城市储备中取货一种当地自产食物和橄榄油并分发至住宅。" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_MODULE_2_DESC, "祭司能扩大住房容量5%，宏伟神庙可像注满水的贮水池一样供水。" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_MODULE_2_DESC, "祭司能降低橄榄油和葡萄酒消耗20%。" },
    {TR_BUILDING_GRAND_TEMPLE_MARS_MODULE_2_DESC, "祭司能降低所有物资消耗10%。" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS_MODULE_2_DESC, "祭司能美化住房并提供娱乐，且无需装饰即可提高周边满意度。" },
    {TR_BUILDING_PANTHEON_MODULE_1_DESC, "城市中所有神庙为万神殿派出祭司，传播信仰和神灵的祝福。" },
    {TR_BUILDING_PANTHEON_MODULE_2_DESC, "接触到万神殿的住宅可升一级。" },
    {TR_BUILDING_GRAND_TEMPLE_CERES_DESC_MODULE_1, "塞丽丝神庙-沃土" }, // Note to translators: This one changed from the previous version, please update.
    {TR_BUILDING_GRAND_TEMPLE_CERES_DESC_MODULE_2, "塞丽丝神庙-雄市" }, // Note to translators: This one changed from the previous version, please update.
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC_MODULE_1, "纳普敦神庙-战车" },
    {TR_BUILDING_GRAND_TEMPLE_NEPTUNE_DESC_MODULE_2, "纳普敦神庙-安居" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC_MODULE_1, "莫丘里神庙-天享" },
    {TR_BUILDING_GRAND_TEMPLE_MERCURY_DESC_MODULE_2, "莫丘里神庙-地用" }, // Note to translators: This one changed from the previous versions, please update.
    {TR_BUILDING_GRAND_TEMPLE_MARS_DESC_MODULE_1, "马尔斯神庙-粮草" },
    {TR_BUILDING_GRAND_TEMPLE_MARS_DESC_MODULE_2, "马尔斯神庙-节用" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS_DESC_MODULE_1, "维纳斯神庙-畅饮" },
    {TR_BUILDING_GRAND_TEMPLE_VENUS_DESC_MODULE_2, "维纳斯神庙-宜居" },
    {TR_BUILDING_PANTHEON_DESC_MODULE_1, "万神殿-朝宗" },
    {TR_BUILDING_PANTHEON_DESC_MODULE_2, "万神殿-不朽" },
    {TR_BUILDING_GRAND_TEMPLE_MENU, "宏伟神庙" },
    {TR_BUILDING_WORK_CAMP, "劳 工 营" },
    {TR_BUILDING_WORK_CAMP_DESC, "劳工在此聚集并将建材运至建筑工地。" },
    {TR_HEADER_HOUSING, "住房"},
    {TR_ADVISOR_HOUSING_ROOM, "城市空房可供"},
    {TR_ADVISOR_HOUSING_NO_ROOM, "城市已无空房。"},
    {TR_ADVISOR_RESIDENCES_DEMANDING_POTTERY, "需要陶器的住宅："},
    {TR_ADVISOR_RESIDENCES_DEMANDING_FURNITURE, "需要家具的住宅："},
    {TR_ADVISOR_RESIDENCES_DEMANDING_OIL, "需要橄榄油的住宅："},
    {TR_ADVISOR_RESIDENCES_DEMANDING_WINE, "需要葡萄酒的住宅："},
    {TR_ADVISOR_TOTAL_NUM_HOUSES, "住宅总数："},
    {TR_ADVISOR_AVAILABLE_HOUSING_CAPACITY, "空房容量："},
    {TR_ADVISOR_TOTAL_HOUSING_CAPACITY, "总容量："},
    {TR_ADVISOR_ADVISOR_HEADER_HOUSING, "人口-住房"},
    {TR_ADVISOR_BUTTON_GRAPHS, "曲线图"},
    {TR_ADVISOR_HOUSING_PROSPERITY_RATING, "住房繁荣评比："},
    {TR_ADVISOR_PERCENTAGE_IN_VILLAS_PALACES, "居住在华宅和宫殿的人口比例："},
    {TR_ADVISOR_PERCENTAGE_IN_TENTS_SHACKS, "居住在帐篷和木屋的人口比例："},
    {TR_ADVISOR_AVERAGE_TAX, "每户平均缴税："},
    {TR_ADVISOR_AVERAGE_AGE, "人口平均年龄："},
    {TR_ADVISOR_PERCENT_IN_WORKFORCE, "劳动力占总人口比例："},
    {TR_ADVISOR_BIRTHS_LAST_YEAR, "去年新生人口："},
    {TR_ADVISOR_DEATHS_LAST_YEAR, "去年死亡人口："},
    {TR_ADVISOR_TOTAL_POPULATION, "位居民（总人口）"},
    {TR_ADVISOR_IN_STORAGE, "在仓库"},
    {TR_ADVISOR_FROM_GRANARIES, "在谷仓"},
    {TR_ADVISOR_DISPATCHING_FOOD_FROM_GRANARIES_TITLE, "从谷仓中分发食物"},
    {TR_ADVISOR_DISPATCHING_FOOD_FROM_GRANARIES_TEXT, "你确定吗?"},
    {TR_ADVISOR_KEEP_STOCKPILING, "保持囤积资源"},
    {TR_ADVISOR_MAX_ATTAINABLE_PROSPERITY_IS, "当前住房水平的最高繁荣值："},
    {TR_REQUIRED_RESOURCES, "当前阶段所需资源："},
    {TR_BUILDING_GRAND_TEMPLE_CONSTRUCTION_DESC, "建造宏伟神庙需要仓库提供建材、劳工营提供劳动力、建筑师协会提供师傅。"},
    {TR_CONSTRUCTION_PHASE, "建造阶段："},
    {TR_ADD_MODULE, "开光授名神庙?"},
    {TR_BUILDING_TEMPLE_MODULE_CONSTRUCTED, "名号已授予。"},
    {TR_BUILDING_CERES_TEMPLE_QUOTE, "起初塞丽丝教会了勤劳的母鹿如何犁地\n怀孕的大地胎动着即将落地的种子。\n她首先为人提供了健康的食物\n然后为这罪恶的世界带来了法律。\n-奥维德-《变形记》-第五卷" },
    {TR_BUILDING_NEPTUNE_TEMPLE_QUOTE, "随着纳普敦放下他的权杖，巨浪滚滚落下\n在波涛汹涌的海面上，浪花抚平他那布满皱纹的脸。\n特里同已在他的召唤下出现在海面上;\n他身着一件提尔长袍;\n同时手里拿着一把弯曲的小号。\n-奥维德-《变形记》-第一卷"},
    {TR_BUILDING_MERCURY_TEMPLE_QUOTE, "牛和肥羊都可以劫走,\n三角桌可以出掉，茶色头的骏马也能卖个好价钱。\n但人的生命和呼吸是回不来的-\n强盗不会太多，贸易买不回性命，\n一旦从那咬紧牙关的人嘴里流出，什么都没了。\n-荷马-《伊利亚特》-第九卷"},
    {TR_BUILDING_MARS_TEMPLE_QUOTE, "马尔斯喜欢的是，修好他受损的车轮和愚钝的战争，\n然后手握擦亮的武器再次奔赴前线，\n用响亮的角声唤醒这散漫的战争。\n-维吉尔-《埃涅阿斯纪》-第八卷" },
    {TR_BUILDING_VENUS_TEMPLE_QUOTE, "长着翅膀的丘比特和他温柔的母亲维纳斯，\n我可真幸福！\n激情的历历在目是那么地动人心弦！\n我的心在我躺着的地方彻底融化了！\n-奥维德-《变形记》-第九卷" },
    {TR_BUILDING_PANTHEON_QUOTE, "天堂之门打开了：朱庇特召唤众神\n众神在大厅里商议。\n他端坐着，遥远地俯视着\n下面的土地、营帐与战争的走向，\n俯视着低等世界的一切。从始至终，\n那等级森严至高无上的元老院巍峨地屹立着。\n-维吉尔-《埃涅阿斯纪》-第十卷" },
    {TR_BUILDING_GRAND_TEMPLE_PHASE_1, "（基台）"},
    {TR_BUILDING_GRAND_TEMPLE_PHASE_2, "（门廊）"},
    {TR_BUILDING_GRAND_TEMPLE_PHASE_3, "（内殿）"},
    {TR_BUILDING_GRAND_TEMPLE_PHASE_4, "（禁地）"},
    {TR_BUILDING_GRAND_TEMPLE_PHASE_5, "（开庙）"},
    {TR_BUILDING_GRAND_TEMPLE_PHASE_1_TEXT, "工人们正在建造抬高神庙的基台，打牢坚实的地基，以经得起时间的风吹雨打。" },
    {TR_BUILDING_GRAND_TEMPLE_PHASE_2_TEXT, "工匠们正在制作门廊，它承载着神庙的祭坛。" },
    {TR_BUILDING_GRAND_TEMPLE_PHASE_3_TEXT, "工程师们正在建造内殿，它是神庙内部存放圣像的地方。" },
    {TR_BUILDING_GRAND_TEMPLE_PHASE_4_TEXT, "禁地的建造工作已开始，朝拜者们在户外聚集，然后开展公共仪式。" },
    {TR_BUILDING_GRAND_TEMPLE_PHASE_5_TEXT, "随着神庙的完工，祭司们聚集在一起进行开庙仪式。" },
    {TR_BUILDING_MENU_TREES, "树   木" },
    {TR_BUILDING_MENU_PATHS, "林 荫 道" },
    {TR_BUILDING_MENU_PARKS, "公   园"},
    {TR_BUILDING_SMALL_POND, "小 池 塘"},
    {TR_BUILDING_LARGE_POND, "大 池 塘"},
    {TR_BUILDING_PINE_TREE, "松   树"},
    {TR_BUILDING_FIR_TREE, "冷 杉 树" },
    {TR_BUILDING_OAK_TREE, "橡   树" },
    {TR_BUILDING_ELM_TREE, "榆   树" },
    {TR_BUILDING_FIG_TREE, "无花果树" },
    {TR_BUILDING_PLUM_TREE, "李   树" },
    {TR_BUILDING_PALM_TREE, "棕 榈 树" },
    {TR_BUILDING_DATE_TREE, "枣   树" },
    {TR_BUILDING_PINE_PATH, "松树小径" },
    {TR_BUILDING_FIR_PATH, "冷杉小径" },
    {TR_BUILDING_OAK_PATH, "橡树小径" },
    {TR_BUILDING_ELM_PATH, "榆树小径" },
    {TR_BUILDING_FIG_PATH, "无花果小径" },
    {TR_BUILDING_PLUM_PATH, "李树小径" },
    {TR_BUILDING_PALM_PATH, "棕榈小径" },
    {TR_BUILDING_DATE_PATH, "枣树小径" },
    {TR_BUILDING_BLUE_PAVILION, "亭   台" },
    {TR_BUILDING_RED_PAVILION, "红色亭台"},
    {TR_BUILDING_ORANGE_PAVILION, "橙色亭台"},
    {TR_BUILDING_YELLOW_PAVILION, "黄色亭台"},
    {TR_BUILDING_GREEN_PAVILION, "绿色亭台" },
    {TR_BUILDING_SMALL_STATUE_ALT, "女神雕像" },
    {TR_BUILDING_SMALL_STATUE_ALT_B, "议员雕像"},
    {TR_BUILDING_OBELISK, "方 尖 碑" },
    {TR_BUILDING_POND_DESC, "池塘由城市的贮水池注满水，为动植物提供水源，同时也是供市民乘凉休息的绿洲。人人都喜欢住在池塘边上。" },
    {TR_BUILDING_WINDOW_POND, "池   塘"},
    {TR_BUILDING_OBELISK_DESC, "一座久负盛名的纪念碑，是一位古代尼罗河国王的作品，并非出自埃及人之手。"},
    {TR_ADVISOR_FINANCE_LEVIES, "建筑维护费"},
    {TR_CONFIRM_DELETE_MONUMENT, "拆除该奇观"},
    {TR_SELECT_EPITHET_PROMPT_HEADER, "选择授予名号"},
    {TR_SELECT_EPITHET_PROMPT_TEXT, "授予名号将使神庙永久投身于敬拜其神灵的某一特性，同时赋予祭司特定的神力。" },
    {TR_BUILDING_INFO_MONTHLY_LEVY, "/月"},
    {TR_BUILDING_MESS_HALL, "军 粮 站"},
    {TR_BUILDING_MESS_HALL_DESC, "军粮站从谷仓中取得食物，供养驻扎在要塞里的将士。军粮不足将导致招兵变慢、士气受损。"},
    {TR_BUILDING_MESS_HALL_FULFILLMENT, "上个月军粮供应："},
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER, "士兵状态：" },
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER_1, "吃好喝足" },
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER_2, "勉强温饱"},
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER_3, "食不果腹"},
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER_4, "饥火烧肠"},
    {TR_BUILDING_MESS_HALL_TROOP_HUNGER_5, "忍痛挨饿"},
    {TR_BUILDING_MESS_HALL_FOOD_TYPES_BONUS_1, "饮食多样化大大提高了部队的士气。"},
    {TR_BUILDING_MESS_HALL_FOOD_TYPES_BONUS_2, "种类多样、营养丰富的饮食大大提高了部队的士气。"},
    {TR_BUILDING_MESS_HALL_NO_SOLDIERS, "无军队需供养。" },
    {TR_BUILDING_MESS_HALL_MONTHS_FOOD_STORED, "已备军粮可供时日（月）：" },
    {TR_MESS_HALL_SPECIAL_ORDERS_HEADER, "军粮站指令"},
    {TR_BUILDING_BARRACKS_FOOD_WARNING, "食物短缺导致士兵招募速度下降。"},
    {TR_BUILDING_BARRACKS_FOOD_WARNING_2, "食物严重短缺大大拖慢了招兵速度。" },
    {TR_BUILDING_LEGION_FOOD_WARNING_1, "近期的食物短缺削弱了部队士气"},
    {TR_BUILDING_LEGION_FOOD_WARNING_2, "近期的食物短缺严重削弱了部队士气"},
    {TR_BUILDING_LEGION_STARVING, "食物短缺" },
    {TR_ADVISOR_TRADE_MAX, "最大量"},
    {TR_ADVISOR_TRADE_NO_LIMIT, "最大量"},
    {TR_ADVISOR_TRADE_IMPORTABLE, "可进口"},
    {TR_ADVISOR_TRADE_EXPORTABLE, "可出口"},
    {TR_ADVISOR_TRADE_NO_BUYERS, "该资源无买家"},
    {TR_ADVISOR_TRADE_NO_SELLERS, "该资源无卖家"},
    {TR_ADVISOR_TRADE_NOT_IMPORTING, "未进口"},
    {TR_ADVISOR_TRADE_NOT_EXPORTING, "未出口"},
    {TR_ADVISOR_OPEN_TO_IMPORT, "开启贸易路线以进口"},
    {TR_ADVISOR_OPEN_TO_EXPORT, "开启贸易路线以出口"},
    {TR_ADVISOR_LEGION_FOOD_SATISFIED, "士兵所需食物充足。"},
    {TR_ADVISOR_LEGION_FOOD_NEEDED, "士兵需要更多食物。" },
    {TR_ADVISOR_LEGION_FOOD_CRITICAL, "你的士兵正在挨饿！"},
    {TR_ADVISOR_LEGION_MONTHS_FOOD_STORED, "军粮站已备军粮可供时日（月）：" },
    {TR_CITY_MESSAGE_TITLE_MESS_HALL_NEEDS_FOOD, "忍饥受饿的士兵" },
    {TR_CITY_MESSAGE_TEXT_MESS_HALL_NEEDS_FOOD, "你的军粮站食物严重短缺，军队士气正在衰弱。请确保你的谷仓储备良好，军粮站能及时取粮。"},
    {TR_CITY_MESSAGE_TEXT_MESS_HALL_MISSING, "城市军粮站被毁，军队正在挨饿，请立刻建造一处军粮站。"},
    {TR_MARKET_SPECIAL_ORDERS_HEADER, "市场指令"},
    {TR_DOCK_SPECIAL_ORDERS_HEADER, "码头指令"},
    {TR_TEMPLE_SPECIAL_ORDERS_HEADER, "神庙指令"},
    {TR_TAVERN_SPECIAL_ORDERS_HEADER, "酒馆指令"},
    {TR_WARNING_NO_MESS_HALL, "你必须先建造军粮站供养士兵。" },
    {TR_WARNING_MAX_GRAND_TEMPLES, "只能建造两座宏伟神庙。" },
    {TR_CITY_MESSAGE_TITLE_GRAND_TEMPLE_COMPLETE, "宏伟神庙建造完成"},
    {TR_CITY_MESSAGE_TEXT_GRAND_TEMPLE_COMPLETE, "祭司和朝拜者们聚众在宏伟神庙举行献祭仪式，你沐浴在神的眷顾下，市民对你的丰功伟绩深感敬畏。"},
    {TR_CITY_MESSAGE_TITLE_MERCURY_BLESSING, "莫丘里的祝福" },
    {TR_CITY_MESSAGE_TEXT_MERCURY_BLESSING, "莫丘里对你的虔诚感到欣慰，他祝福了你的工业链，为你的工匠挖出了生产原料。"},
    {TR_FIGURE_TYPE_WORK_CAMP_WORKER, "工头"},
    {TR_FIGURE_TYPE_WORK_CAMP_SLAVE, "搬运工"},
    {TR_FIGURE_TYPE_WORK_CAMP_ARCHITECT, "建筑师"},
    {TR_FIGURE_TYPE_MESS_HALL_SUPPLIER, "军需官"},
    {TR_FIGURE_TYPE_MESS_HALL_COLLECTOR, "炊事员"},
    {TR_BUILDING_CERES_TEMPLE_MODULE_DESC, "宏伟神庙将塞丽丝神庙的祭司组织起来向饥饿的市民分发食物和橄榄油。"},
    {TR_BUILDING_VENUS_TEMPLE_MODULE_DESC, "宏伟神庙可让维纳斯神庙的祭司向市民供应神圣的葡萄酒。" },
    {TR_BUILDING_MARS_TEMPLE_MODULE_DESC, "宏伟神庙将马尔斯神庙的祭司组织起来为军粮站提供食物。"},
    {TR_BUILDING_SMALL_TEMPLE_CERES_NAME, "塞丽丝神庙"},
    {TR_BUILDING_SMALL_TEMPLE_NEPTUNE_NAME, "纳普敦神庙"},
    {TR_BUILDING_SMALL_TEMPLE_MERCURY_NAME, "莫丘里神庙"},
    {TR_BUILDING_SMALL_TEMPLE_MARS_NAME, "马尔斯神庙"},
    {TR_BUILDING_SMALL_TEMPLE_VENUS_NAME, "维纳斯神庙"},
    {TR_FIGURE_TYPE_PRIEST_SUPPLIER, "祭司" },
    {TR_BUILDING_DOCK_CITIES_CONFIG_DESC, "海上贸易城市：" },
    {TR_BUILDING_DOCK_CITIES_NO_ROUTES, "无海上贸易路线。" },
    // Transcription of mission_exact4.wav
    {TR_PHRASE_FIGURE_MISSIONARY_EXACT_4, "\"我将尽我所能让这些野蛮人冷静下来，我相信和他们交谈后，他们就不会再来侵扰城市了。\"" },
    {TR_CITY_MESSAGE_TITLE_PANTHEON_FESTIVAL, "年度节庆"},
    {TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_CERES, "虔诚的信徒们在神庙前汇聚一堂，庆祝谷神节以表达对塞丽丝女神的敬意，农民们纷纷举行祭祀活动以求得来年的丰收。"},
    {TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_NEPTUNE, "今天是纪念纳普敦的海神节，忠实的市民们用树枝和树叶建造小屋，在炎炎的烈日下尽情狂欢。"},
    {TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_MERCURY, "商人们成群结队地前来庆祝商神节。人们将圣水洒向商船和仓库，希望获得莫丘里的保佑。"},
    {TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_MARS, "市民们聚集在城外庆祝赛马节，以寻求马尔斯的青睐，赛场的空气中充满着雷鸣般的马蹄声和战车的嘎吱声，这是对战神忠诚的致敬。"},
    {TR_CITY_MESSAGE_TEXT_PANTHEON_FESTIVAL_VENUS, "忠实的市民们聚集在一起庆祝爱神节，向神圣的维纳斯致敬，祈求在爱情上获得好运。"},
    {TR_TOOLTIP_BUTTON_DELETE_READ_MESSAGES, "删除已读信息"},
    {TR_TOOLTIP_BUTTON_MOTHBALL_ON, "关停该建筑"},
    {TR_TOOLTIP_BUTTON_MOTHBALL_OFF, "开启该建筑"},
    {TR_TOOLTIP_BUTTON_ACCEPT_MARKET_LADIES, "允许市场大妈在此收购物资"},
    {TR_TOOLTIP_BUTTON_ACCEPT_TRADE_CARAVAN, "允许商队在此贸易"},
    {TR_TOOLTIP_BUTTON_ACCEPT_TRADE_SHIPS, "允许商船在此贸易"},
    {TR_BUILDING_LIGHTHOUSE, "灯   塔"},
    {TR_BUILDING_CARAVANSERAI, "商队驿站"},
    {TR_BUILDING_CARAVANSERAI_DESC, "商队在此歇脚休息、喂食坐骑。陆地贸易歇脚时间占总时间的一半。"},
    {TR_CARAVANSERAI_SPECIAL_ORDERS_HEADER, "商队驿站指令"},
    {TR_BUILDING_CARAVANSERAI_PHASE_1, "（地基）"},
    {TR_BUILDING_CARAVANSERAI_PHASE_1_TEXT, "工程师为商站打下坚实的地基。"},
    {TR_FIGURE_TYPE_CARAVANSERAI_SUPPLIER, "商队驿站供应人" },
    {TR_FIGURE_TYPE_CARAVANSERAI_COLLECTOR, "商队驿站收购工" },
    {TR_BUILDING_CARAVANSERAI_POLICY_TITLE, "陆地贸易政策" },
    {TR_BUILDING_CARAVANSERAI_NO_POLICY, "无陆地贸易政策。" },
    {TR_BUILDING_CARAVANSERAI_POLICY_TEXT, "为城市选择一项陆地贸易政策，你也可以随时切换成其他政策。" },
    {TR_BUILDING_CARAVANSERAI_POLICY_1_TITLE, "陆地出口导向型" },
    {TR_BUILDING_CARAVANSERAI_POLICY_1, "陆地出口导向型政策：陆地出口收入提高20%，但陆地进口价格上涨10%。" },
    {TR_BUILDING_CARAVANSERAI_POLICY_2_TITLE, "陆地进口导向型" },
    {TR_BUILDING_CARAVANSERAI_POLICY_2, "陆地进口导向型政策：陆地进口价格降低20%，但陆地出口收入下降10%。" },
    {TR_BUILDING_CARAVANSERAI_POLICY_3_TITLE, "陆地种类导向型" },
    {TR_BUILDING_CARAVANSERAI_POLICY_3, "陆地种类导向型政策：商队携带额外4种贸易物资，但商队驿站的食物消耗量增加20%。" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_1, "（地基）" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_2, "（基座）" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_3, "（塔楼）" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_4, "（顶冠）" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_1_TEXT, "工程师们正在打下坚实的地基，以承得起巨型石塔的重量。" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_2_TEXT, "石匠们正在建造基座，将灯塔的火焰抬高至地平线之上。" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_3_TEXT, "石匠们正持续为这座高塔铺设阶梯，灯塔的高度与日俱增。" },
    {TR_BUILDING_LIGHTHOUSE_PHASE_4_TEXT, "工程师们正在对灯塔进行最后的修饰，不久后其光芒将照耀千里，指引远方归家的船只。" },
    {TR_BUILDING_LIGHTHOUSE_CONSTRUCTION_DESC, "建造灯塔需要仓库提供建材、劳工营提供劳动力、建筑师协会提供师傅。" },
    {TR_BUILDING_LIGHTHOUSE_BONUS_DESC, "这座高塔顶部的光芒指引着来自世界各地的船只，以平安抵达您的城市。渔船移速提高10%，海上风暴持续时间减半。" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_TITLE, "海上贸易政策" },
    {TR_BUILDING_LIGHTHOUSE_NO_POLICY, "无海上贸易政策。" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_TEXT, "为城市选择一项海上贸易政策，你也可以随时切换成其他政策。" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_1_TITLE, "海上出口导向型" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_1, "海上出口导向型政策：海上出口收入提高20%，但海上进口价格上涨10%。" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_2_TITLE, "海上进口导向型" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_2, "海上进口导向型政策：海上进口价格降低20%，但海上出口收入下降10%。" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_3_TITLE, "海上种类导向型" },
    {TR_BUILDING_LIGHTHOUSE_POLICY_3, "海上种类导向型政策：商船携带额外4种贸易物资，但灯塔的木材消耗量增加20%。" },
    {TR_EDITOR_ALLOWED_BUILDINGS_MONUMENTS, "奇观"},
    {TR_CITY_MESSAGE_TEXT_LIGHTHOUSE_COMPLETE, "建成的灯塔；耸立在地平线上的一座巨型石塔，希望它的灯焰能指引海上的船只平安归家，直到永远。" },
    {TR_CITY_MESSAGE_TEXT_PANTHEON_COMPLETE, "万神殿建造完成。这座奇观建筑神圣不可侵犯，展现出罗马众神和其人民的伟大力量。" },
    {TR_CITY_MESSAGE_TITLE_MONUMENT_COMPLETE, "奇观已建成" },
    {TR_CITY_MESSAGE_TITLE_NEPTUNE_BLESSING, "来自纳普敦的祝福"},
    {TR_CITY_MESSAGE_TEXT_NEPTUNE_BLESSING, "鉴于你的虔诚，纳普敦让城市的商人在接下来的12个月里畅通无阻，在此期间出口收入提高50%。"},
    {TR_CITY_MESSAGE_TITLE_VENUS_BLESSING, "来自维纳斯的祝福" },
    {TR_CITY_MESSAGE_TEXT_VENUS_BLESSING, "取悦于你的崇敬，维纳斯祝福你的人民永葆青春、健康且幸福，提高了劳动力人口占比。在维纳斯的微笑下城市的情绪得到改善。" },
    {TR_BUILDING_MENU_STATUES, "雕   像" },
    {TR_BUILDING_MENU_GOV_RES, "政府官的宅邸" },
    {TR_OVERLAY_ROADS, "道    路" },
    {TR_NO_EXTRA_ASSETS_TITLE, "无法加载额外资源" },
    {TR_NO_EXTRA_ASSETS_MESSAGE,
        "无法加载Augustus额外资源。\n"
        "原因可能是‘assets’目录缺失或版本老旧。\n"
        "请确保‘assets’目录下的文件为最新版，可从Github上下载。" },
    {TR_WARNING_WATER_NEEDED_FOR_LIGHTHOUSE, "灯塔必须临水建立"},
    {TR_TOOLTIP_OVERLAY_PANTHEON_ACCESS, "该住宅可接触到万神殿的所有5位神灵"},
    {TR_BUILDING_LEGION_FOOD_BONUS, "充足的食物正在提高士气" },
    {TR_BUILDING_LEGION_FOOD_STATUS, "食物状态"},
    {TR_TOOLTIP_BUTTON_ACCEPT_QUARTERMASTER, "允许军需官在此取得食物"},
    {TR_WARNING_RESOURCES_NOT_AVAILABLE, "你无法获得所需材料"},
    {TR_CONFIG_GP_CH_MONUMENTS_BOOST_CULTURE_RATING, "已建成的宏伟神庙+8点文化评比"},
    {TR_CONFIG_GP_CH_DISABLE_INFINITE_WOLVES_SPAWNING, "禁止无限产生狼群"},
    {TR_BUTTON_BACK_TO_MAIN_MENU, "退出至主菜单" },
    {TR_LABEL_PAUSE_MENU, "暂停" },
    {TR_OVERLAY_LEVY, "维 护 费" },
    {TR_TOOLTIP_OVERLAY_LEVY, " Dn用于每月建筑维护。" },
    {TR_MAP_EDITOR_OPTIONS, "场景设定" },
    {TR_BUILDING_TAVERN, "酒   馆" },
    {TR_BUILDING_GRAND_GARDEN, "宏伟花园" },
    {TR_BUILDING_TAVERN_DESC_1, "该酒馆无工人前来运营，无法开张。" },
    {TR_BUILDING_TAVERN_DESC_2, "该酒馆无葡萄酒供给，无法开张。" },
    {TR_BUILDING_TAVERN_DESC_3, "只要葡萄酒的供应源源不断，该酒馆就能持续为人民提供娱乐，再提供些肉类可进一步提高其吸引力。" },
    {TR_BUILDING_TAVERN_DESC_4, "醇厚的酒香和扑鼻的烤肉香味吸引了一大群顾客前来聚会、享乐和赌博。" },
    {TR_FIGURE_TYPE_BARKEEP, "酒馆老板" },
    {TR_FIGURE_TYPE_BARKEEP_SUPPLIER, "酒馆供应人" },
    {TR_OVERLAY_TAVERN, "酒    馆" },
    {TR_TOOLTIP_OVERLAY_TAVERN_1, "该住宅未连接到酒馆，或酒馆的葡萄酒已用尽。" },
    {TR_TOOLTIP_OVERLAY_TAVERN_2, "酒馆老板已有许久未路经此处，该住宅即将失去酒馆的服务。" },
    {TR_TOOLTIP_OVERLAY_TAVERN_3, "带着葡萄酒的酒馆老板刚路经该住宅。" },
    {TR_TOOLTIP_OVERLAY_TAVERN_4, "带着葡萄酒和肉类的酒馆老板刚路经该住宅。" },
    {TR_TOOLTIP_OVERLAY_TAVERN_5, "带着葡萄酒的酒馆老板近期路经过该住宅。" },
    {TR_TOOLTIP_OVERLAY_TAVERN_6, "带着葡萄酒和肉类的酒馆老板近期路经过该住宅，让欢乐的时光开始吧！" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_1, "居民们讨厌听到你的名字。"},
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_2, "居民们对你感到十分愤怒。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_3, "居民们对你表示愤怒。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_4, "居民们对你感到十分不满。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_5, "居民们对你表示不满。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_6, "居民们对你感到生气。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_7, "居民们对你态度冷淡。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_8, "居民们对你感到满意。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_9, "居民们对你感到比较满意。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_10, "居民们对你感到十分满意。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_11, "居民们对你表示热爱。" },
    {TR_BUILDING_WINDOW_HOUSE_SENTIMENT_12, "居民们把你当作神一般崇拜。" },
    {TR_BUILDING_WINDOW_HOUSE_UPSET_HIGH_TAXES, "居民们对高税负表示不满。" },
    {TR_BUILDING_WINDOW_HOUSE_UPSET_LOW_WAGES, "居民们对低薪资表示不满。" },
    {TR_BUILDING_WINDOW_HOUSE_UPSET_UNEMPLOYMENT, "居民们对缺少就业机会表示不满。" },
    {TR_BUILDING_WINDOW_HOUSE_UPSET_SQUALOR, "居民们对质量欠佳的居住条件感到失望。" },
    {TR_BUILDING_WINDOW_HOUSE_SUGGEST_ENTERTAINMENT, "居民们希望得到更多娱乐。" },
    {TR_BUILDING_WINDOW_HOUSE_SUGGEST_FOOD, "居民们希望饮食更加多样化。" },
    {TR_BUILDING_WINDOW_HOUSE_SUGGEST_DESIRABILITY, "居民们希望进一步提高住房满意度。" },
    {TR_BUILDING_WINDOW_HOUSE_RECENT_EVENT_POSITIVE, "最近发生的事件令居民们振奋。" },
    {TR_BUILDING_WINDOW_HOUSE_RECENT_EVENT_NEGATIVE, "最近发生的事件使居民们失去信心。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_TAVERN_COVERAGE, "酒馆" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_HEADER, "赛事" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_DESC, "赞助大竞技场举办大型赛事，需消耗个人资金和城市资源。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_BUTTON, "举办赛事" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_PREPARING, "大型赛事的准备工作正在如火如荼地进行中。" },
    {TR_SELECT_GAMES_HEADER, "赛事" },
    {TR_SELECT_GAMES_TEXT, "赛事将在大竞技场内举办，需消耗个人资金和城市资源。" },
    {TR_BUILDING_ARENA, "竞 技 场" },
    {TR_BUILDING_HORSE_STATUE, "骑手雕像" },
    {TR_BUILDING_DOLPHIN_FOUNTAIN, "海豚喷泉" },
    {TR_BUILDING_HEDGE_DARK, "翠绿树篱" },
    {TR_BUILDING_HEDGE_LIGHT, "向日树篱" },
    {TR_BUILDING_GARDEN_WALL, "花园围墙" },
    {TR_BUILDING_LEGION_STATUE, "军团雕像" },
    {TR_BUILDING_DECORATIVE_COLUMN, "大理石圆柱" },
    {TR_BUILDING_COLOSSEUM_PHASE_1, "（地窖）" },
    {TR_BUILDING_COLOSSEUM_PHASE_2, "（地基）" },
    {TR_BUILDING_COLOSSEUM_PHASE_3, "（拱廊）" },
    {TR_BUILDING_COLOSSEUM_PHASE_4, "（顶座）" },
    {TR_BUILDING_COLOSSEUM_PHASE_1_TEXT, "工人们正在挖掘地窖-地下通道和机械室，一切壮观场面都始于此地。" },
    {TR_BUILDING_COLOSSEUM_PHASE_2_TEXT, "大竞技场墙壁的形状勾画出层层梯位上罗马平民和皇帝坐在一起的盛景。" },
    {TR_BUILDING_COLOSSEUM_PHASE_3_TEXT, "优雅美观的拱廊高耸入云，把大竞技场这个庞然建筑高高撑起。" },
    {TR_BUILDING_COLOSSEUM_PHASE_4_TEXT, "大竞技场的顶座直入云霄，其墙壁上雕刻着闪闪发光的大理石雕像。" },
    {TR_BUILDING_HIPPODROME_PHASE_1, "（赛道）" },
    {TR_BUILDING_HIPPODROME_PHASE_2, "（地基）" },
    {TR_BUILDING_HIPPODROME_PHASE_3, "（看台）" },
    {TR_BUILDING_HIPPODROME_PHASE_4, "（正门）" },
    {TR_BUILDING_HIPPODROME_PHASE_1_TEXT, "这片偌大的建造区正在被精心地勘察和清理，以开展一项规模前所未有的工程。" },
    {TR_BUILDING_HIPPODROME_PHASE_2_TEXT, "赛道周围正在打造出入通道和支撑性建筑。" },
    {TR_BUILDING_HIPPODROME_PHASE_3_TEXT, "石匠们正在刻凿可容下成千上万名观众的石座。" },
    {TR_BUILDING_HIPPODROME_PHASE_4_TEXT, "除了赛道，工匠们正在打造一座配得上罗马众神和罗马人民的纪念碑。" },
    {TR_BUILDING_MONUMENT_CONSTRUCTION_DESC, "建造奇观需要仓库提供建材、劳工营提供劳动力、建筑师协会提供师傅。" },
    {TR_BUILDING_MONUMENT_CONSTRUCTION_HALTED, "建造已暂停。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_ARENA_COVERAGE, "竞技场" },
    {TR_BUILDING_INFO_TOURISM, "（旅行者）" },
    {TR_CITY_MESSAGE_TEXT_COLOSSEUM_COMPLETE, "大竞技场建造完成！让角斗大赛开始吧！" },
    {TR_CITY_MESSAGE_TEXT_HIPPODROME_COMPLETE, "赛马场建造完成！市民观众们都等着你一声令下让比赛开始！" },
    {TR_CITY_MESSAGE_TITLE_COLOSSEUM_WORKING, "开幕赛" },
    {TR_CITY_MESSAGE_TITLE_HIPPODROME_WORKING, "比赛开始" },
    {TR_CITY_MESSAGE_TEXT_COLOSSEUM_WORKING, "大竞技场的开幕赛已开始，在你的命令下，勇士们将用鲜血供奉这座奇观！" },
    {TR_CITY_MESSAGE_TEXT_HIPPODROME_WORKING, "为了观看战车开幕赛，城内的人们一走而空，纷纷涌入城外的赛马场。就在战车大门打开的那一刻，震耳欲聋的欢呼声响彻全场！" },
    {TR_WINDOW_GAMES_OPTION_1, "举办海军演义" },
    {TR_WINDOW_GAMES_OPTION_2, "举办人兽厮杀" },
    {TR_WINDOW_GAMES_OPTION_3, "举办元旦庆祝赛" },
    {TR_WINDOW_GAMES_OPTION_4, "举办奥运会" },
    {TR_WINDOW_GAMES_OPTION_5, "举办罗马运动会" },
    {TR_WINDOW_GAMES_OPTION_1_DESC, "大竞技场将放水淹没整个战场，以再现一场大海战。次年里己方军队移动速度和远程战斗力获得提高。" },
    {TR_WINDOW_GAMES_OPTION_2_DESC, "大竞技场将放出阴森恐怖的野兽，角斗士们要么猎杀野兽，要么被野兽当场处决，以取悦广大罗马民众。次年里所有犯罪、暴动、起义活动将被镇压。角斗士将帮助城市免受下一次入侵。" },
    {TR_WINDOW_GAMES_OPTION_3_DESC, "大竞技场将举行的角斗赛事旨在新年的第一天里纪念罗马众神，祈求财富与商业繁荣。次年双倍贸易限额。" },
    {TR_WINDOW_GAMES_OPTION_4_DESC, "赛马场将举办奥运会，城市将招待大量游客，如果你的运动员在比赛中为城市赢得了荣誉，这将永久提高旅游业和支持度评比。" },
    {TR_WINDOW_GAMES_OPTION_5_DESC, "大竞技场将举办罗马运动会，举国上下的选手来到你的城市参赛，如此盛景必定能提高皇帝和平民对你来年的支持度。" },
    {TR_WINDOW_GAMES_COST, "耗费：" },
    {TR_WINDOW_GAMES_PERSONAL_FUNDS, "（个人资金）" },
    {TR_WINDOW_GAMES_NOT_ENOUGH_FUNDS, "个人资金不足。" },
    {TR_WINDOW_GAMES_NOT_ENOUGH_RESOURCES, "资源储备不足。" },
    {TR_WINDOW_GAMES_NO_VENUE, "举办场地未建造或场地无工人。" },
    {TR_BUILDING_SMALL_TEMPLE_PHASE_1, "（建设中）" },
    {TR_BUILDING_SMALL_TEMPLE_PHASE_1_TEXT, "石匠和工程师们正在用闪闪发光的大理石打造这座神圣的建筑。" },
    {TR_BUILDING_SMALL_TEMPLE_CONSTRUCTION_DESC, "建造该神庙需要仓库提供建材、劳工营提供劳动力、建筑师协会提供师傅。" },
    {TR_CITY_MESSAGE_TEXT_NAVAL_GAMES_PLANNING, "贮水池中的水源正缓缓地注入大竞技场内，木匠们开始组装栩栩如生的微型战船，专门为水上作战而训练的角斗士们也整装待发，很快一场海战即将打响！" },
    {TR_CITY_MESSAGE_TEXT_NAVAL_GAMES_STARTING, "大竞技场变成了一片人工湖，角斗士们用生命重现昔日罗马在海上的伟大胜利，随着血液与海水的交融，观众们发出雷鸣般的欢呼。海军演义已开始！" },
    {TR_CITY_MESSAGE_TEXT_NAVAL_GAMES_ENDING, "大竞技场进入了一段漫长的清理过程，它的水需要被排干以待常用。在未来的几年里你的人民将不断诉说这段水上壮景。" },
    {TR_CITY_MESSAGE_TEXT_ANIMAL_GAMES_PLANNING, "奇奇怪怪的船货开始出现在你的城市里，来自遥远彼地的商人将凶残可怖的野兽押送至大竞技场地下的牢笼里。很快，一场惨烈壮观的表演即将展现给在座的观众们。" },
    {TR_CITY_MESSAGE_TEXT_ANIMAL_GAMES_STARTING, "死刑犯和追寻终极荣耀的角斗士们将在这里以凶牙利爪的形式直面死亡。随着一阵号角声，人兽厮杀开始了！" },
    {TR_CITY_MESSAGE_TEXT_ANIMAL_GAMES_ENDING, "最后一只野兽已被杀死，它笨重地倒在大竞技场的黄沙之中，野兽之血和斗士之血交织在了一起，这场人兽厮杀结束了。" },
    {TR_CITY_MESSAGE_TEXT_KALENDS_GAMES_PLANNING, "我们要以一场荣耀的角斗迎接新年、致敬众神。作为回报，我们祈求财富、好运以及对商业的祝福。" },
    {TR_CITY_MESSAGE_TEXT_KALENDS_GAMES_STARTING, "元月初一的清晨，赛事开始了，祭司们用动物祭祀的同时，角斗士们披盔戴甲、浴血奋战，为了寻求神灵的眷顾流尽最后一滴血。"},
    {TR_CITY_MESSAGE_TEXT_KALENDS_GAMES_ENDING, "占卜显示我们伟大的赛事取悦了众神，献祭仪式也成功闭幕，我们预计今年将是财运亨通的一年！"},
    {TR_CITY_MESSAGE_TEXT_OLYMPIC_GAMES_PLANNING, "所有的目光都聚焦于我们的城市，奥林匹克运动会的举办将为城市带来来自世界各地的游客、参赛选手以及罗马政要人物。至少需要一年的时间才能做好一切准备工作。"},
    {TR_CITY_MESSAGE_TEXT_OLYMPIC_GAMES_STARTING, "这一天终于来了，奥运圣火已熊熊燃起，城市街道一走而空，赛马场中人山人海，奥运赛事开始了！"},
    {TR_CITY_MESSAGE_TEXT_OLYMPIC_GAMES_ENDING, "圣火已熄灭，游客和市民们陆续离场，归家途中大家虽感疲惫，却依然沉浸在奥运的喜庆氛围之中。永恒的荣耀属于你，你成功举办了这场古老而神圣的庆典，它象征着凡人的力量与荣誉。" },
    {TR_CITY_MESSAGE_TEXT_IMPERIAL_GAMES_PLANNING, "随着罗马运动会的宣布，远自帝国边境的全国人民纷纷涌入你的城市，所有人都希望在接下来的比赛中取得优胜。至少需要一年的时间才能做好一切准备工作。" },
    {TR_CITY_MESSAGE_TEXT_IMPERIAL_GAMES_STARTING, "随着仪仗队庄严地走完，罗马运动会开始了。愿朱庇特亲自挑选赛跑、摔跤以及其他耐力和敏捷比赛的冠军。大竞技场挤得人满为患，人们不仅盼着大赛开始，更望着按惯例分发的面包和橄榄油礼物。罗马运动会开始了！" },
    {TR_CITY_MESSAGE_TEXT_IMPERIAL_GAMES_ENDING, "罗马运动会的最后一天接近尾声，每个市民吃饱喝足、意犹未尽，大家都尝到了罗马生活的美好与伟大。荣耀归众神，荣耀归冠军，荣耀归父母官！" },
    {TR_CITY_MESSAGE_TITLE_GREAT_GAMES, "大型赛事"},
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_COOLDOWN, "距离可举办新赛事所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_PREPARING_NG, "距离海军演义开始所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_UNDERWAY_NG, "海军演义正在进行。在观众们的欢呼下，战场上水花四溅，船板被踩得嘎吱作响，角斗士们发出的战吼声令人振奋不已。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_PREPARING_AG, "距离人兽厮杀开始所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_UNDERWAY_AG, "人兽厮杀正在进行。就在野兽慢慢逼近它的人类猎物时，观众们肩并着肩，场内尖叫声不绝于耳，有的人甚至喊破了嗓子。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_PREPARING_KG, "距离元旦庆祝赛开始所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_UNDERWAY_KG, "元旦庆祝赛正在进行。动物祭品和熏香的气味盖过了竞技场中刺鼻的鲜血和汗臭。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_PREPARING_OG, "距离奥运会开始所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_UNDERWAY_OG, "奥运会正在进行。圣火日夜不熄，运动员们为不朽的荣耀而争相竞逐。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_PREPARING_IG, "距离罗马运动会开始所剩月份：" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_UNDERWAY_IG, "罗马运动会正在进行。每位参赛者都用自己的鲜血、汗水和泪水来证明自己是最优秀的罗马人。" },
    {TR_WINDOW_BUILDING_GAMES_REMAINING_DURATION, "大型赛事将再持续" }, // ...XX Days, 
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_COOLDOWN_TEXT, "近期已举办大型赛事。" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_GAMES_UNDERWAY, "大型赛事正在进行。城市中充斥着来自各地的游客和狂欢活动。" },
    {TR_WINDOW_BUILDING_ARENA_CLOSED, "竞技场已关闭。有鸟儿在空座上筑起了巢。" },
    {TR_WINDOW_BUILDING_ARENA_NO_SHOWS, "该竞技场既没有狮子也没有角斗士，仅提供丁点娱乐。" },
    {TR_WINDOW_BUILDING_ARENA_BOTH_SHOWS, "该竞技场举办角斗士和猎杀动物表演，以取悦当地民众。" },
    {TR_WINDOW_BUILDING_ARENA_NEEDS_LIONS, "定期举行的角斗士表演一直娱乐着大众，要是有斗狮表演就更为壮观了。" },
    {TR_WINDOW_BUILDING_ARENA_NEEDS_GLADIATORS, "竞技场中饥饿的野兽四处徘徊寻找猎物，由于缺乏训练有素的角斗士，表演持续时间短暂。" },
    {TR_BUILDING_MARS_TEMPLE_MODULE_DESC_NO_MESS, "一旦完工，该神庙会为你的军粮站收集食物。" },
    {TR_OVERLAY_ARENA_COL, "竞 技 场" },
    {TR_TOOLTIP_OVERLAY_ARENA_COL_1, "该住宅未连接到竞技场或大竞技场。" },
    {TR_TOOLTIP_OVERLAY_ARENA_COL_2, "该住宅可在竞技场中看到一种表演。" },
    {TR_TOOLTIP_OVERLAY_ARENA_COL_3, "该住宅可在竞技场中看到两种表演。" },
    {TR_TOOLTIP_OVERLAY_ARENA_COL_4, "该住宅可在大竞技场中看到一种表演。" },
    {TR_TOOLTIP_OVERLAY_ARENA_COL_5, "该住宅可在大竞技场中看到两种表演。" },
    {TR_TOOLTIP_OVERLAY_PROBLEMS_STRIKE, "罢工工人" },
    {TR_TOOLTIP_OVERLAY_PROBLEMS_NO_WATER_ACCESS, "未连接到水源" },
    {TR_TOOLTIP_OVERLAY_PROBLEMS_CARTPUSHER, "等待推车工" },
    {TR_TOOLTIP_OVERLAY_PROBLEMS_NO_RESOURCES, "无可用资源" },
    {TR_TOOLTIP_OVERLAY_PROBLEMS_MOTHBALLED, "建筑搁置待用" },
    {TR_WINDOW_BUILDING_TOURISM_DISABLED, "该类建筑过多-游客正在避开此地。" },
    {TR_WINDOW_BUILDING_TOURISM_ANNUAL, "今年来自游客的收入：" },
    {TR_WINDOW_BUILDING_WHARF_MOTHBALLED, "你的贸易顾问命令渔业停产。"},
    {TR_WINDOW_ADVISOR_FINANCE_INTEREST_TRIBUTE, "贡金/利息"},
    {TR_WINDOW_ADVISOR_TOURISM, "各式各样"},
    {TR_WINDOW_FIGURE_TOURIST, "该游客已消费："},
    {TR_FIGURE_TYPE_TOURIST,  "游客"},
    {TR_MAP_EDITOR_OPTIONS, "场景设定" },
    {TR_SAVEGAME_LARGER_VERSION_TITLE, "存档版本不兼容" },
    {TR_SAVEGAME_LARGER_VERSION_MESSAGE, "即将载入的存档出自Augustus较新版本。\n请更新Augustus至最新版。" },
    {TR_BUILDING_COLONNADE, "柱   廊" },
    {TR_BUILDING_LARARIUM, "神   龛" },
    {TR_WINDOW_BUILDING_LARARIUM_DESC, "这座小型圣祠旨在供奉家庭守护神拉列斯-罗马人的祖灵。在这里可以进行小型献祭和祈祷。"},
    {TR_BUILDING_WATCHTOWER, "哨   塔"},
    {TR_BUILDING_WATCHTOWER_DESC, "驻扎在该塔上的弓箭手们时刻保持警惕，提防外来入侵者，同时楼下的街道由看守人巡逻。" },
    {TR_BUILDING_WATCHTOWER_DESC_NO_SOLDIERS, "该哨塔需要卫兵才能保卫我们的城市。"},
    {TR_BUILDING_NYMPHAEUM, "宁芙神庙"},
    {TR_BUILDING_NYMPHAEUM_DESC, "该大型神庙旨在供奉水仙女宁芙-泉水、河流、海洋里的小神灵。它能赋予这片土地-美丽和富饶，予以城市神圣的眷顾。" },
    {TR_BUILDING_SMALL_MAUSOLEUM, "小型陵墓"},
    {TR_BUILDING_SMALL_MAUSOLEUM_DESC, "该陵墓是城市里的贵族为已故先人打造的安息之地，也是许多活着的人羡慕的地方。" },
    {TR_BUILDING_LARGE_MAUSOLEUM, "大型陵墓"},
    {TR_BUILDING_LARGE_MAUSOLEUM_DESC, "这座华丽的陵墓有着抛光的大理石围墙和雕塑，反映着贵族们的伟大功绩，因而赢得了在此安息的特权。" },
    {TR_FIGURE_TYPE_WATCHMAN, "看守人" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_MAINTENANCE, "切换是否允许巡警和工程师通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_PRIEST, "切换是否允许祭司通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_MARKET, "切换是否允许市场大妈通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_ENTERTAINER, "切换是否允许娱乐艺人通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_EDUCATION, "切换是否允许教育行人通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_MEDICINE, "切换是否允许医护人员通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_TAX_COLLECTOR, "切换是否允许税吏通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_LABOR_SEEKER, "切换是否允许招工人通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_MISSIONARY, "切换是否允许传教士通过" },
    {TR_TOOLTIP_BUTTON_ROADBLOCK_PERMISSION_WATCHMAN, "切换是否允许看守人通过" },
    {TR_HOTKEY_DUPLICATE_TITLE, "热键已占用"},
    {TR_HOTKEY_DUPLICATE_MESSAGE, "该键位已设定为以下功能："},
    {TR_BUILDING_GARDEN_PATH, "花园小径" },
    {TR_BUTTON_GO_TO_SITE, "前往施工现场" },
    {TR_BUTTON_HALT_MONUMENT_CONSTRUCTION, "暂停建造" },
    {TR_BUTTON_RESUME_MONUMENT_CONSTRUCTION, "继续建造" },
    {TR_RESOURCE_FISH, "鱼肉" },
    {TR_WARNING_VARIANT_TOGGLE, "按下'R'转向键可旋转建筑方向"},
    {TR_BUILDING_SCHOOL_UPGRADE_DESC, "这座学校正在运转，本地的发展让市民们能够扩建该建筑，为学童提供更多空间。"},
    {TR_BUILDING_THEATRE_UPGRADE_DESC, "这座戏院正在运转，本地的发展让市民们能够扩建该建筑，为观众提供更多座位。" },
    {TR_BUILDING_LIBRARY_UPGRADE_DESC, "这座图书馆正在运转，本地的发展让市民们能够扩建该建筑，为学者提供更多书卷和读书角。" },
    {TR_WINDOW_BUILDING_INFO_WARNING_NO_MONUMENT_ROAD_ACCESS, "该奇观的施工场地未连接至道路，无法接收建材，将道路连接至其中一块中段瓷砖即可。"},
    {TR_WINDOW_BUILDING_WORKSHOP_STRIKING, "由于城市情绪低下，该作坊的工人已宣布罢工且拒绝工作！" },
    {TR_CITY_WARNING_SECESSION, "平民们拒绝上工！" },
    {TR_CITY_WARNING_WAREHOUSE_BREAKIN, "一座仓库已遭洗劫！" },
    {TR_CITY_WARNING_GRANARY_BREAKIN, "一座谷仓已遭洗劫！" },
    {TR_CITY_WARNING_THEFT, "公共集会所或元老院的资金遭到偷窃！" },
    {TR_CITY_MESSAGE_TITLE_LOOTING, "城市正遭洗劫！"},
    {TR_CITY_MESSAGE_TEXT_LOOTING, "一座仓库或谷仓被愤怒的市民们掠抢一空！城市情绪低下可能导致此类事件再次发生。"},
    {TR_SIDEBAR_EXTRA_INVASIONS, "入侵" },
    {TR_SIDEBAR_EXTRA_INVASION_UNDERWAY, "敌军来犯！" },
    {TR_SIDEBAR_EXTRA_NO_INVASIONS, "未发现入侵" },
    {TR_SIDEBAR_EXTRA_INVASION_IMMINENT, "入侵迫在眉睫" },
    {TR_SIDEBAR_EXTRA_ENEMIES_CLOSING, "敌军正在接近" },
    {TR_SIDEBAR_EXTRA_ENEMIES_DISTANT, "敌军距离遥远" },
    {TR_SIDEBAR_EXTRA_GODS, "神灵" },
    {TR_SIDEBAR_EXTRA_REQUESTS_VIEW_ALL, "查看所有" },
    {TR_SIDEBAR_EXTRA_REQUESTS_SMALL_FORCE, "小批军队"},
    {TR_SIDEBAR_EXTRA_REQUESTS_AVERAGE_FORCE, "适量军队"},
    {TR_SIDEBAR_EXTRA_REQUESTS_LARGE_FORCE, "大批军队"},
    {TR_SIDEBAR_EXTRA_REQUESTS_SEND, "发出请求"},
    {TR_SIDEBAR_EXTRA_REQUESTS_STOCK, "存储"},
    {TR_SIDEBAR_EXTRA_REQUESTS_UNSTOCK, "停止存储"},
    {TR_TOOLTIP_ADVISOR_HOUSING_GRAPH_BUTTON, "查看人口曲线图" },
    {TR_TOOLTIP_ADVISOR_POPULATION_HOUSING_BUTTON, "拜访你的住房顾问" },
    {TR_BUILDING_MONUMENT_CONSTRUCTION_ARCHITECT_NEEDED, "该阶段建造这座奇观所需的材料已备齐，工人们正在等待建筑师协会派出师傅前来指点进一步施工。" },
    {TR_RETURN_ALL_TO_FORT, "全军回营" },
    {TR_TOOLTIP_ADVISOR_ENTERTAINMENT_GAMES_BUTTON, "赛事信息" },
    {TR_WINDOW_BUILDING_GOVERNMENT_LARGE_STATUE_WATER_WARNING, "如果能打开这座雕像的喷泉，它看起来会更加宏伟，请为之供水。" },
    {TR_OPTION_MENU_APPLY, "应用" },
    {TR_OPTION_MENU_COST, "这将耗费" },
    {TR_FIGURE_TYPE_LOOTER, "劫匪" },
    {TR_FIGURE_TYPE_ROBBER, "强盗" },
    {TR_OVERLAY_SENTIMENT, "情    绪" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_NO_COVERAGE, "没有人" },
    {TR_WINDOW_ADVISOR_ENTERTAINMENT_FULL_COVERAGE, "所有人" },
    {TR_TOOLTIP_ADVISOR_TRADE_LAND_POLICY, "选择一项陆地贸易政策"},
    {TR_TOOLTIP_ADVISOR_TRADE_LAND_POLICY_REQUIRED, "需要建造商队驿站才能设立陆地贸易政策"},
    {TR_TOOLTIP_ADVISOR_TRADE_SEA_POLICY, "选择一项海上贸易政策"},
    {TR_TOOLTIP_ADVISOR_TRADE_SEA_POLICY_REQUIRED, "需要建造灯塔才能设立海上贸易政策"},
    {TR_TOOLTIP_HOLD_GAME, "举办赛事"},
    {TR_TOOLTIP_NO_GAME, "不举办赛事"},
    {TR_WARNING_NEARBY_WOLF, "无法在狼群周边建造" },
    {TR_MARKET_TRADING, "买卖中"},
    {TR_MARKET_NOT_TRADING, "未买卖"},
    {TR_TEMPLE_DISTRIBUTING, "分发中"},
    {TR_TEMPLE_NOT_DISTRIBUTING, "未分发"},
    {TR_ADVISOR_CHIEF_NO_IMMIGRATION_SQUALOR, "恶劣的居住条件和帐篷阻止了移民迁入"},
    {TR_FIGURE_TYPE_LIGHTHOUSE_SUPPLIER, "灯塔看守人"},
    {TR_WINDOW_GAMES_NO_WATER_ACCESS, "维纳丝未接触到贮水池。"},
};

void translation_simplified_chinese(const translation_string **strings, int *num_strings)
{
    *strings = all_strings;
    *num_strings = sizeof(all_strings) / sizeof(translation_string);
}
