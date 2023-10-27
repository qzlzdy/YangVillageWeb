add_executable(homepage.wt
    main.cpp
    Homepage.cpp
)

target_link_libraries(homepage.wt
    fcgi wt wtfcgi
)
