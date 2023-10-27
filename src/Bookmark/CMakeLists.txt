add_executable(bookmark.wt
    main.cpp
    Bookmark.cpp
    Cluster.cpp
)

target_link_libraries(bookmark.wt
    fcgi wt wtfcgi wtdbo wtdbosqlite3
)
