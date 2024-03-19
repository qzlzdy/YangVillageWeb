add_executable(toolkits.wt
    main.cpp
    Echo.cpp
)

target_link_libraries(toolkits.wt
    fcgi wt wtfcgi
)
