cmake_minimum_required(VERSION 3.9)

set(PROJECT etfg_v1)
project(${PROJECT})
#        VERSION "1.0.0")
set(PROJECT_VERSION "1.0.0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(Qt5 COMPONENTS Sql Xml Qml Core Widgets REQUIRED)
include_directories(/usr/include/treefrog)
include_directories(/usr/local/include)
include_directories(views)
include_directories(models)
include_directories(models/sqlobjects)
include_directories(helpers)
include_directories(utils)

#add_library(foo1 SHARED IMPORTED)
#set_property(TARGET foo1 PROPERTY IMPORTED_LOCATION "/usr/local/lib/libqtcsv")
link_libraries(/usr/local/lib)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#   utils
add_library(utils SHARED
        utils/ColumnMap.cpp
        utils/ColumnMap.h
        utils/ModelImport.cpp
        utils/ModelImport.h
        utils/ModelImportProcessor.cpp
        utils/ModelImportProcessor.h
        utils/Cusip.cpp
        utils/Cusip.h
        utils/Isin.cpp
        utils/Isin.h
        utils/Identifier.cpp
        utils/Identifier.h
        utils/Sedol.cpp
        utils/Sedol.h
        utils/Figi.cpp
        utils/Figi.h
)

set_target_properties(utils PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 SOVERSION 1.0)
target_link_libraries(utils pthread treefrog rt Qt5::Core Qt5::Network Qt5::Sql Qt5::Qml Qt5::Xml qtcsv)


#   helper
add_library(helper SHARED
        helpers/applicationhelper.cpp
        helpers/applicationhelper.h
)

set_target_properties(helper PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 SOVERSION 1.0)
target_link_libraries(helper pthread treefrog rt utils Qt5::Core Qt5::Network Qt5::Sql Qt5::Qml Qt5::Xml qtcsv)

#	model
add_library(model SHARED
        models/sqlobjects/mdconstituentstageobject.h
        models/mdconstituentstage.cpp
        models/mdconstituentstage.h
)

set_target_properties(model PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 SOVERSION 1.0)
target_link_libraries(model pthread treefrog rt helper utils Qt5::Core Qt5::Network Qt5::Sql Qt5::Qml Qt5::Xml )

#	controller
add_library(controller SHARED
        controllers/applicationcontroller.cpp
        controllers/applicationcontroller.h
        controllers/mdconstituentstagecontroller.cpp
        controllers/mdconstituentstagecontroller.h
)

set_target_properties(controller PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 SOVERSION 1.0)
target_link_libraries(controller pthread treefrog rt helper utils model Qt5::Core Qt5::Network Qt5::Sql Qt5::Qml Qt5::Xml )

#  view
add_library(view SHARED
        views/_src/mdconstituentstage_createView.cpp
        views/_src/mdconstituentstage_indexView.cpp
        views/_src/mdconstituentstage_saveView.cpp
        views/_src/mdconstituentstage_showView.cpp
        views/_src/mdconstituentstage_loadView.cpp
)

set_target_properties(view PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 1 SOVERSION 1.0)
target_link_libraries(view pthread treefrog rt helper utils model Qt5::Core Qt5::Network Qt5::Sql Qt5::Qml Qt5::Xml )

#add_executable(figi utils/Figi.cpp)
#target_link_libraries(figi Qt5::Core utils)
#
#add_executable(cusip utils/Cusip.cpp)
#target_link_libraries(cusip Qt5::Core utils)
#
#add_executable(isin utils/Isin.cpp)
#target_link_libraries(isin Qt5::Core utils)
#
#add_executable(sedol utils/Sedol.cpp)
#target_link_libraries(sedol Qt5::Core utils)

add_custom_command(
        TARGET controller
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)

add_custom_command(
        TARGET model
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)

add_custom_command(
        TARGET view
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)

add_custom_command(
        TARGET helper
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)

add_custom_command(
        TARGET utils
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
)
#add_custom_command(TARGET controller
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:controller> ${PROJECT_SOURCE_DIR}/lib
#        COMMENT "Copying controller to lib directory")
#
#add_custom_command(TARGET model
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:model> ${PROJECT_SOURCE_DIR}/lib)
#
#add_custom_command(TARGET view
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:view> ${PROJECT_SOURCE_DIR}/lib)
#
#add_custom_command(TARGET helper
#        POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:helper> ${PROJECT_SOURCE_DIR}/lib)

#install(TARGETS controller LIBRARY DESTINATION ${PROJECT_LIBRARY_DIR}/lib)
install(TARGETS controller DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(TARGETS model DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(TARGETS view DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(TARGETS helper DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(TARGETS utils DESTINATION ${PROJECT_SOURCE_DIR}/lib)

