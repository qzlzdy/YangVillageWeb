add_subdirectory(Bookmark)
add_subdirectory(Homepage)
add_subdirectory(Portfolio)

add_executable(yangvillage.wt
    main.cpp
)

target_link_libraries(yangvillage.wt
    Bookmark
    Homepage
    Portfolio
    wt wthttp wtdbo wtdbosqlite3
)
