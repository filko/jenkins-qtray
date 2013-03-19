cmake_minimum_required(VERSION 2.8)
project(jenkins-qtray)

find_package(Qt4 REQUIRED)

set(QT_USE_QTNETWORK TRUE)

set(QOBJECTS Task)

foreach(qobject ${QOBJECTS})
  set(headers ${headers} src/${qobject}.hh)
endforeach(qobject)
file(GLOB sources src/*.cc)

set(jenkins-qtray_SOURCES ${sources})
set(jenkins-qtray_HEADERS ${headers})
qt4_wrap_cpp(jenkins-qtray_MOC ${jenkins-qtray_HEADERS})

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

add_executable(jenkins-qtray ${jenkins-qtray_SOURCES} ${jenkins-qtray_MOC})
target_link_libraries(jenkins-qtray ${QT_LIBRARIES})
