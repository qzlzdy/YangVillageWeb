add_executable(broadcast.wt
    main.cpp
    Broadcast.cpp
)

target_link_libraries(broadcast.wt
    fcgi wt wtfcgi
)
