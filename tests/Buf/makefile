include prorab.mk



this_name := tests


#compiler flags
this_cxxflags += -std=c++11
this_cxxflags += -Wall
this_cxxflags += -DDEBUG
this_cxxflags += -fstrict-aliasing #strict aliasing!!!
this_cxxflags += -O3

ifeq ($(prorab_os),macosx)
    this_cxxflags += -stdlib=libc++ #this is needed to be able to use c++11 std lib
    this_ldlibs += -lc++
endif

this_srcs := main.cpp tests.cpp

this_ldlibs += -lstdc++

$(eval $(prorab-build-app))

include $(prorab_this_dir)../test_target.mk
