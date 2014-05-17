import sys

def options(opt):
        opt.load('compiler_cxx')

def configure(conf):
        conf.load('compiler_cxx')

        if conf.env.CXX_NAME == 'msvc':
            conf.env.append_value('CXXFLAGS', ['/EHsc'])

def build(bld):
        bld.program(source='TestSample.cpp TestRunner.cpp', 
                    target='app', 
                    includes='gmock-1.7.0/include gmock-1.7.0/gtest/include',
                    use='gmock')

        bld.stlib(source='gmock-1.7.0/src/gmock-all.cc gmock-1.7.0/gtest/src/gtest-all.cc', 
                  includes='gmock-1.7.0/ gmock-1.7.0/gtest gmock-1.7.0/include/ gmock-1.7.0/gtest/include/', 
                  target='gmock')
