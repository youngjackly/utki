include prorab.mk



this_name := tests


#compiler flags

this_cxxflags += -Wall
this_cxxflags += -DDEBUG
this_cxxflags += -fstrict-aliasing #strict aliasing!!!
this_cxxflags += -std=c++11
this_cxxflags += -O3

this_srcs += main.cpp tests.cpp


ifeq ($(prorab_os),macosx)
    this_cxxflags += -stdlib=libc++ #this is needed to be able to use c++11 std lib
    this_ldlibs += -lc++
else ifeq ($(prorab_os),windows)
else
    this_ldlibs += -lpthread
endif

this_ldflags += -L$(prorab_this_dir)../../src/

this_ldlibs += -lstdc++

$(eval $(prorab-build-app))

include $(prorab_this_dir)../test_target.mk
