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
