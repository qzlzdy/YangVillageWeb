--    YangVillage Website
--    Copyright (C) 2024  Qzlzdy
--
--    This program is free software: you can redistribute it and/or modify
--    it under the terms of the GNU Affero General Public License as published
--    by the Free Software Foundation, either version 3 of the License, or
--    (at your option) any later version.
--
--    This program is distributed in the hope that it will be useful,
--    but WITHOUT ANY WARRANTY; without even the implied warranty of
--    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--    GNU Affero General Public License for more details.
--
--    You should have received a copy of the GNU Affero General Public License
--    along with this program.  If not, see <https://www.gnu.org/licenses/>.
{-# LANGUAGE OverloadedStrings     #-}
{-# LANGUAGE QuasiQuotes           #-}
{-# LANGUAGE TemplateHaskell       #-}
{-# LANGUAGE TypeFamilies          #-}
import           Yesod

data YangVillageWeb = YangVillageWeb

statUrl :: String
statUrl = "https://staus.yangvillage.top"

mkYesod "YangVillageWeb" [parseRoutes|
/ HomeR GET
|]

yangvillageLayout :: Widget -> Handler Html
yangvillageLayout widget = do
    pc <- widgetToPageContent widget
    withUrlRenderer
        [hamlet|
            $doctype 5
            <html>
                <head>
                    <title>#{pageTitle pc}
                    <meta charset="utf-8">
                    <meta name="author" content="骑着轮子的羊">
                    $maybe desc <- pageDescription pc
                        <meta name="description" content=#{desc}>
                    <meta name="viewpoint" content="width=device-width, initial-scale=1">
                    <meta name="robots" content="index,follow">
                    ^{pageHead pc}
                <body>
                    ^{pageBody pc}
        |]

instance Yesod YangVillageWeb where
    defaultLayout = yangvillageLayout

homeContents :: Widget
homeContents = 
    [whamlet|
        <p .h2 .text-center .text-decoration-line-through>PHP是世界上最好的语言
        <p .h1 .text-center>PHP就是一坨
        <p .fs-3 .text-center>我的主页崩了，我修不好它
        <p .fs-3 .text-center>但你可以去我别的页面看看
        <p .text-center .text-decoration-line-through>前面的蛆，以后再来探索吧
        <a href=#{statUrl}>
            <p .fs-3 .text-center>羊村统计局
    |]

centerWidget :: Widget -> Widget
centerWidget widgets =
    [whamlet|
        <div .position-absolute .start-50 .top-50 .translate-middle>
            ^{widgets}
    |]

getHomeR :: Handler Html
getHomeR = defaultLayout $ do
    setTitle "羊村"
    setDescriptionIdemp "这里是羊村，你可能走错了。但你既然已经来了，就请随便逛逛吧。这里可以有任何内容——这取决于村长的决定。通常，这些内容是二次元、计算机、Minecraft。"
    addStylesheetRemoteAttrs "https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/css/bootstrap.min.css" [
        ("rel", "stylesheet"),
        ("integrity", "sha384-SgOJa3DmI69IUzQ2PVdRZhwQ+dy64/BUtbMJw1MZ8t5HZApcHrRKUc4W0kG879m7"),
        ("crossorigin", "anonymous")
        ]
    addScriptRemoteAttrs "https://cdn.jsdelivr.net/npm/bootstrap@5.3.5/dist/js/bootstrap.bundle.min.js" [
        ("integrity", "sha384-k6d4wzSIapyDyv1kpU366/PK5hCdSbCRGRCMv+eplOQJWyd1fbcAu9OCUj5zNLiq"),
        ("crossorigin", "anonymous")
        ]
    centerWidget homeContents

main :: IO ()
main = warp 8001 YangVillageWeb
