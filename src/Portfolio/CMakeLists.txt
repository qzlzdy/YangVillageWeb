add_executable(portfolio.wt
    main.cpp
    About.cpp
    Contact.cpp
    ContactFormModel.cpp
    ContactFormView.cpp
    Footer.cpp
    Header.cpp
    Home.cpp
    NavigationBar.cpp
    Portfolio.cpp
    Profile.cpp
    ProjectInfo.cpp
    Projects.cpp
    Resume.cpp
    Section.cpp
    Skills.cpp
    SocialLinks.cpp
)

target_link_libraries(portfolio.wt
    fcgi wt wtfcgi wtdbo wtdbosqlite3
)
