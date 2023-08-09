-- bookmarks definition
CREATE TABLE bookmarks (
    "id" INTEGER PRIMARY KEY AUTOINCREMENT,
    "catalog" TEXT,
    "title" TEXT,
    "desc" TEXT,
    "url" TEXT
);

-- bookmark urls
  -- references
BEGIN TRANSACTION;
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'C++参考手册',
    '一种被广泛使用的计算机程序设计语言',
    'https://en.cppreference.com/w/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Python官方文档',
    '一种广泛使用的解释型、高级和通用的编程语言',
    'https://docs.python.org/3/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Qt框架官方文档',
    '一个跨平台的C++应用程序开发框架',
    'https://doc.qt.io/qt-6/classes.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'CMake官方文档',
    '一个开源的跨平台自动化建构系统',
    'https://cmake.org/cmake/help/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'PyTorch官方文档',
    '一个开源的Python机器学习库',
    'https://pytorch.org/docs/stable/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Doxygen官方手册',
    '一个适用于多种语言的文档生成器',
    'https://doxygen.nl/manual/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Nonebot2官方文档',
    '跨平台Python异步聊天机器人框架',
    'https://v2.nonebot.dev/docs/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'SQLite官方文档',
    '小型关系数据库管理系统',
    'https://www.sqlite.org/docs.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'boost库官方文档',
    '一组扩展C++功能的经过同行评审且开放源码程序库',
    'https://www.boost.org/doc/libs/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Wt框架官方文档',
    '用于C++编程语言的以小部件为中心的开源Web框架',
    'https://www.webtoolkit.eu/wt/documentation'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Bootstrap框架官方文档',
    '一组用于网站和网络应用程序开发的开源前端框架',
    'https://getbootstrap.com/docs/5.2/getting-started/introduction/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'PlantUML官方文档',
    '用纯文本语言绘制图表的开源软件',
    'https://plantuml.com/zh/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Graphviz官方文档',
    '一个由AT&T实验室启动的开源工具包',
    'https://graphviz.org/doc/info/lang.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Chisel3官方参考手册',
    '一个现代硬件设计语言',
    'https://www.chisel-lang.org/api/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Verilator官方文档',
    '一个将Verilog转换为C++或SystemC中精确到周期的行为模型的开源软件工具',
    'https://veripool.org/guide/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Eigen库官方文档',
    '用于线性代数，矩阵和向量运算，几何变换，数值求解器和相关算法的模板标题的高级C++库',
    'https://eigen.tuxfamily.org/dox/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Funkwhale官方文档',
    '一个自托管、现代、免费和开源的音乐服务器',
    'https://docs.funkwhale.audio/administrator/index.html'
);
  -- wikis
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    'Arch Linux',
    '一个独立开发的x86-64架构通用GNU/Linux发行版',
    'https://archlinux.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    'Wikipedia',
    '维基媒体基金会运营的由受众共同编辑和管理的在线超文本出版物',
    'https://en.wikipedia.org/wiki/Wiki'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    'Arch Linux ARM',
    'ARM架构的Arch Linux发行版',
    'https://archlinuxarm.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    '萌娘百科',
    '万物皆可萌的百科全书~',
    'https://zh.moegirl.org.cn/Mainpage#/desktop/index'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    'LifeWiki',
    '康威生命游戏是在二维正方形网格上进行的细胞自动机游戏',
    'https://conwaylife.com/'
);
  -- Anime
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '动漫花园',
    '一個動漫愛好者交流的平台,提供最及時,最全面的服务',
    'https://share.dmhy.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'AGE动漫',
    'Age动漫专业的在线动漫网站，动漫免费在线观看，高品质画质，实时更新，追番利器!',
    'https://www.agemys.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '異世界動漫',
    '異世界動漫',
    'https://www.sbdm.net/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'Nyaa',
    '一个专注于东亚媒体（包括动画、漫画、音乐等）的BitTorrent社区',
    'https://nyaa.si/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'AniList',
    '通过AniList跟踪、发现和分享动漫。通过评论和推荐发现评分最高的热门节目。免费注册！',
    'https://anilist.co/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '天使动漫防丢',
    '从这里找到天使动漫主站',
    'http://www.tsdm.vip/'
);
  -- game
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    '企鹅物流数据统计',
    '企鹅物流旗下数据处理部门（误），致力于明日方舟各素材的掉率统计',
    'https://penguin-stats.io/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    'PRTS.wiki',
    '一个非盈利性质的明日方舟资料Wiki网站',
    'https://prts.wiki/w/%E9%A6%96%E9%A1%B5'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    '群星wiki',
    '群星|Stellaris中文维基',
    'https://qunxing.huijiwiki.com/wiki/%E7%BE%A4%E6%98%9F'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    'MC百科',
    '我的世界MOD百科，提供Minecraft(我的世界)MOD(模组)物品资料介绍教程攻略和MOD下载',
    'https://www.mcmod.cn/'
);
  -- tools
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'DeepL',
    '即时翻译文本&完整的文档文件。为个人和团队提供准确的翻译。每天有数百万人使用DeepL进行翻译',
    'https://www.deepl.com/translator'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'trace.moe',
    '动漫场景搜索引擎。查询准确时刻和剧集',
    'https://trace.moe/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'SourceNAO',
    '查找自2008年后的图片来源',
    'https://saucenao.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'WolframAlpha',
    '使用Wolfram的突破性技术和知识库计算答案，数百万学生和专业人士都信赖Wolfram的技术和知识库',
    'https://www.wolframalpha.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'Should I Remove It?',
    '帮你决定从电脑中卸载哪些程序和软件',
    'https://www.shouldiremoveit.com/index.aspx'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'FlightAware',
    '最好的飞行跟踪站点：实时跟踪地图、飞行状态、航空公司航班延误、私人/通用航空飞行及机场信息',
    'https://zh.flightaware.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'draw.io',
    '一款免费的在线图表软件，用于制作流程图、流程图、组织结构图、UML、ER 和网络图',
    'https://app.diagrams.net/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'ReceiveSMS',
    '免费在线接收短信。无需注册。用于短信验证的临时电话号码',
    'https://www.receivesms.io/'
);
  -- communities
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    'Github',
    '全球最大同♂️性交流网站（不是）',
    'https://github.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    '臭鼬娘俱乐部',
    '好想闻美少女的屁啊',
    'https://www.skunkgirl.cc/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    'stack overflow',
    '全球最大开发者在线社区',
    'https://stackoverflow.com/questions'
);
  -- article
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'The Catalog of Design Patterns',
    '设计模式目录',
    'https://refactoring.guru/design-patterns/catalog'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'Decoded: GNU coreutils',
    'coreutils源码解析',
    'https://www.maizure.org/projects/decoded-gnu-coreutils/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'systemd by example',
    'systemd原理解析',
    'https://systemd-by-example.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'datavizproject',
    '收集数据可视化，获得灵感并找到合适的类型',
    'https://datavizproject.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'PrintableSearch',
    '一个搜索引擎，用于从最好的3D模型网站查找顶级3D打印模型、可打印文件和stls',
    'https://www.printablesearch.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'AI auto-subtitling',
    'AI字幕',
    'https://www.spapas.net/2023/05/22/ai-auto-subtitling/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'Makefile Tutorial',
    'Makefile原理解析',
    'https://makefiletutorial.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'DIY Raspberry Pi NAS',
    'DIY NAS',
    'https://www.instructables.com/DIY-Raspberry-Orange-Pi-NAS-That-Really-Looks-Like/'
);
COMMIT;

-- messages definition
CREATE TABLE messages (
	"id" INTEGER PRIMARY KEY AUTOINCREMENT,
    "version" INTEGER,
	"name" TEXT,
	"email" TEXT,
	"subject" TEXT,
	"message" TEXT
);

-- projects definition
CREATE TABLE projects (
	"id" INTEGER PRIMARY KEY AUTOINCREMENT,
	"type" INTEGER,
	"title" TEXT,
	"begin" TEXT,
	"end" TEXT,
	"repoAddr" TEXT,
	"repoName" TEXT,
	"desc" TEXT
);

-- project informations
-- 1: C/C++ 2: Embedded 3: Java 4: Android 5: Python
BEGIN TRANSACTION;
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(5,
    '基于Scrapy + MongoDB的Instgram爬虫',
    '2018-09-01', '2019-01-01',
    NULL, NULL, NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(3,
    '基于Spring boot + MySQL的爬虫后台',
    '2019-03-01', '2019-07-01',
    NULL, NULL, NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(5,
    '基于Protege + D2RQ + Apache Jena Fuseki的知识图谱应用',
    '2019-09-01', '2020-01-01',
    NULL, NULL, NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(2,
    '基于STM32F207VCT6的触摸屏双人棋类游戏',
    '2019-09-01', '2020-01-01',
    NULL, NULL, NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(4,
    '基于Android + 百度地图SDK + 知识图谱的可语音交互室内导航APP',
    '2020-03-01', '2020-06-01',
    'https://github.com/longjie1107/AndroidShopQuery.git', 'AndroidShopQuery',
    NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(1,
    'Dolphin DB插件', '2021-02-08', '2021-06-25',
    'https://github.com/dolphindb/DolphinDBPlugin.git', 'DolphinDBPlugin',
    '<a href="https://dolphindb.com">浙江智臾科技有限公司</a>实习期间工作。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(5,
    '基于生成对抗网络的动漫头像生成软件开发',
    '2020-12-01', '2021-04-01',
    'https://github.com/qzlzdy/Anivatar.git', 'Anivatar',
    '毕业设计。基于<a href="https://github.com/NVlabs/stylegan2.git">StyleGAN2</a>改进实现。后端使用<a href="https://flask.palletsprojects.com/en/2.3.x/">Flask框架</a>开发'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(2,
    '基于STM32F207的触摸屏国际象棋游戏',
    '2022-03-01', '2022-06-01',
    'https://github.com/qzlzdy/EhduChess.git', 'EhduChess',
    NULL
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(2,
    'Bad Apple (HDU)',
    '2022-03-01', '2022-06-01',
    'https://github.com/qzlzdy/EhduBadApple.git', 'EhduBadApple',
    'bilibili<a href="https://www.bilibili.com/video/BV1Ua411x7R2">投稿视频</a>源代码。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(5,
    '猫猫ちゃん色图机器人', '2018-12-18', NULL,
    'https://github.com/qzlzdy/Neko-Chan2.git', 'Neko-Chan2',
    '<a href="https://im.qq.com/index/">腾讯QQ</a>聊天机器人。基于<a href="https://nonebot.dev/">Nonebot 2框架</a>开发，后端使用<a href="https://github.com/mamoe/mirai.git">Mirai2</a>。功能包括：每日新番更新提醒；色图；每日工作提醒；<a href="https://www.swordart-online.net">ソードアート・オンライン</a>重大事件提醒；俄罗斯转盘；24岁，是学生；炼铜提醒；复读机；我很可爱，请给我钱。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(1,
    '羊村网站', '2022-09-17', NULL,
    'https://github.com/qzlzdy/YangVillageWeb.git', 'YangVillageWeb',
    '<a href="https://yangvillage.top">羊村(本网站)</a>源代码。基于<a href="https://www.webtoolkit.eu/wt/">Wt框架</a>开发，前端主题使用<a href="https://getbootstrap.com">Bootstrap</a>。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(1,
    '脑电采集控制软件', '2021-10-08', '2022-11-16',
    'https://github.com/qzlzdy/EegStreamer.git', 'EegStreamer',
    '基于<a href="https://www.qt.io">Qt框架</a>开发。适用于实验室自研基于水凝胶电极的脑电采集设备BrainWave。软件接口兼容<a href="https://openbci.com">OpenBCI</a>。主要功能有：1.实时显示多通道脑电信号；2.集成SSVEP实验范式；3.离线数据保存；4.功率谱分析；5.频谱分析。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(1,
    '脑控俄罗斯方块', '2022-11-16', '2022-04-06',
    'https://github.com/qzlzdy/SsvepTetris.git', 'SsvepTetris',
    '基于<a href="https://www.qt.io">Qt框架</a>开发。通过脑机接口游玩俄罗斯方块。脑机接口基于SSVEP，无需训练，即插即用。脑电采集硬件设备接口兼容<a href="https://openbci.com">OpenBCI</a>。'
);
INSERT INTO projects
("type", "title", "begin", "end", "repoAddr", "repoName", "desc")
VALUES(1,
    '其他各种代码片段', '2017-09-18', NULL,
    'https://github.com/qzlzdy/Daily-Code.git', 'Daily-Code',
    '日常使用及不适合独立建库的代码。包括：<a href="https://ak.hypergryph.com">明日方舟</a>限定干员概率计算程序；<a href="https://acm.hdu.edu.cn">HDOJ</a>刷题源代码；<a href="https://www.minecraft.net">MineCraft</a> Mod <a href="https://terrafirmacraft.com">TerraFirmaCreaft</a>锻造辅助计算工具；<a href="https://github.com/qzlzdy/Neko-Chan2.git">猫猫ちゃん</a>色图库PC端辅助工具；Trackers列表同步脚本。'
);
COMMIT;
