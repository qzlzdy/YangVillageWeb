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
    '为程序员提供C/C++语言及标准库的完整在线参考资料',
    'https://en.cppreference.com/w/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Python官方文档',
    '一种清晰而强大的面向对象编程语言',
    'https://docs.python.org/3/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Qt框架官方文档',
    '跨平台的C++应用程序开发框架',
    'https://doc.qt.io/qt-6/classes.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'CMake官方文档',
    '开源的跨平台自动化建构系统',
    'https://cmake.org/cmake/help/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'PyTorch官方文档',
    '开源的Python机器学习库',
    'https://pytorch.org/docs/stable/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Doxygen官方手册',
    '适用于多种语言的文档生成器',
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
    '用于网站和网络应用程序开发的开源前端框架',
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
    '由AT&T实验室启动的开源工具包',
    'https://graphviz.org/doc/info/lang.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Chisel3官方参考手册',
    '现代硬件设计语言',
    'https://www.chisel-lang.org/api/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Verilator官方文档',
    '将Verilog转换为C++或SystemC中精确到周期的行为模型的开源软件工具',
    'https://veripool.org/guide/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Eigen库官方文档',
    '用于线性代数、矩阵和向量运算、几何变换、数值求解器和相关算法的模板标题的高级C++库',
    'https://eigen.tuxfamily.org/dox/index.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Grav官方文档',
    '一个快速、简单、灵活的基于文件的网络平台',
    'https://learn.getgrav.org/17/content'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Navidrome官方文档',
    '兼容Subsonic API的轻量级音乐服务器',
    'https://www.navidrome.org/docs/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ref',
    'Penrose官方文档',
    '只需在纯文本中输入符号，即可创建精美的图表。',
    'https://penrose.cs.cmu.edu/docs/ref'
);
  -- wikis
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('wiki',
    'Arch Linux',
    '独立开发的x86-64架构通用GNU/Linux发行版',
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
    '一個動漫愛好者交流的平台，提供最及時，最全面的服务',
    'https://share.dmhy.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'AGE动漫',
    '在线动漫网站',
    'https://www.agedm.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '異世界動漫',
    '在线动漫网站',
    'https://www.mikudm.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'Nyaa',
    '专注于东亚媒体的BitTorrent社区',
    'https://nyaa.si/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'AniList',
    '通过AniList跟踪、发现和分享动漫。通过评论和推荐发现评分最高的热门节目。',
    'https://anilist.co/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '天使动漫防丢',
    '从这里找到天使动漫主站',
    'http://www.tsdm.vip/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '番组计划',
    '专注于动漫、音乐、游戏领域，帮助你分享、发现与结识同好的ACG网络',
    'https://bangumi.tv/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '蜜柑计划',
    '新一代的动漫下载站',
    'https://mikanani.me/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'DLsite',
    '日本最大的二次元综合下载商店之一',
    'https://www.dlsite.com/index.html?locale=ja_JP'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    'GGBases',
    '提供最全面的GalGame、同人遊戲BT下載，以及功能完善的標簽檢索功能。',
    'https://www.ggbases.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('anime',
    '熱辣漫畫',
    '為全球華人提供高質量中文全本漫畫、同人志。',
    'https://www.manga2022.com/'
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
    '干员培养表',
    '明日方舟干员培养表',
    'https://ark-nights.com/table'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    'PRTS.wiki',
    '非盈利性质的明日方舟资料Wiki网站',
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
    '我的世界MOD百科，提供Minecraft MOD物品资料介绍教程攻略和MOD下载',
    'https://www.mcmod.cn/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('game',
    'FlightGear wiki',
    'FlightGear官方文档',
    'https://wiki.flightgear.org/Main_Page'
);
  -- tools
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'DeepL',
    '即时翻译文本&完整的文档文件。为个人和团队提供准确的翻译。',
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
    '使用Wolfram的突破性技术和知识库计算答案',
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
    'explain shell',
    '命令解释搜索引擎',
    'https://explainshell.com'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    'Microsoft 365',
    '办公套件',
    'https://www.landiannews.com/download/103741.html
');
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('tool',
    '清华源',
    '清华大学开源软件镜像站',
    'https://mirror.tuna.tsinghua.edu.cn/'
);
  -- communities
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    'Github',
    '全球最大同♂️性交友网站（不是）',
    'https://github.com/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    '臭鼬娘俱乐部',
    '好想闻美少女放的屁啊',
    'https://www.skunkgirl.cc/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    'stack overflow',
    '全球第二大同♂️性交友网站（别闹了啊）全球最大开发者在线社区',
    'https://stackoverflow.com/questions'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('comm',
    'THISVID',
    '#1 PLACE FOR YOUR HOMEMADE VIDEOS',
    'https://thisvid.com/'
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
    '17 Golden Rules of Financial Safety',
    '个人财务管理',
    'https://thetaoofwealth.wordpress.com/2013/02/17/harry-brownes-17-golden-rules-of-financial-safety/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'Around The World blog',
    '随机游戏地图',
    'https://frozenfractal.com/blog/2023/11/2/around-the-world-1-continents/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('artc',
    'LaTeX教程',
    'LaTeX教程',
    'https://latex.lierhua.top/zh/'
);
  -- Ypologist
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'RISC-V Specifications',
    'RISC-V架构官方文档下载',
    'https://riscv.org/technical/specifications/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'Linux source code',
    'Linux内核源码',
    'https://elixir.bootlin.com/linux/latest/source'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'LLVM source code',
    'LLVM源码',
    'https://elixir.bootlin.com/llvm/latest/source'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'Linux From Scratch',
    'LFS在线文档',
    'https://www.linuxfromscratch.org/lfs/read.html'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'The LLVM Compiler Infrastructure',
    'LLVM编译器官网',
    'https://llvm.org/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'Xiangshan 官方文档',
    'Xiangshan架构官方文档',
    'https://xiangshan-doc.readthedocs.io/zh_CN/latest/arch/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'OpenFPGA官方文档',
    '可定制FPGA架构快速原型开发开放源代码框架。',
    'https://openfpga.readthedocs.io/en/master/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'Verilog-to-Routing官方文档',
    '为FPGA架构和CAD研发提供的开源框架',
    'https://docs.verilogtorouting.org/en/latest/'
);
INSERT INTO bookmarks
("catalog", "title", "desc", "url")
VALUES('ypo',
    'GPT fdisk Tutorial',
    'gdisk官网',
    'https://www.rodsbooks.com/gdisk/'
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
