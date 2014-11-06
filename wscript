import sys
from waflib.Tools import waf_unit_test

def options(opt):
    opt.load('compiler_cxx waf_unit_test')

def configure(conf):
    conf.load('compiler_cxx waf_unit_test')

    if conf.env.CXX_NAME == 'msvc':
        conf.env.append_value('CXXFLAGS', ['/EHsc'])

    if conf.env.CXX_NAME == 'gcc':
        conf.env.append_value('CXXFLAGS', ['-std=c++0x'])
        conf.env.append_value('LINKFLAGS', ['-pthread'])

def build(bld):
    bld.program(features='test',
                source='TestOcrAccount.cpp \
                        TestOcrAccountStreamReader.cpp \
                        TestOcrDigit.cpp \
                        TestRunner.cpp',
                target='test', 
                includes='gmock-1.7.0/include gmock-1.7.0/gtest/include',
                use='gmock ocr')

    bld.program(source='Story1.cpp',
                target='story1', 
                use='ocr')

    bld.program(source='Story3.cpp',
                target='story3', 
                use='ocr')

    bld.program(source='Story4.cpp',
                target='story4', 
                use='ocr')

    bld.stlib(source='gmock-1.7.0/src/gmock-all.cc gmock-1.7.0/gtest/src/gtest-all.cc', 
              includes='gmock-1.7.0/ gmock-1.7.0/gtest gmock-1.7.0/include/ gmock-1.7.0/gtest/include/', 
              target='gmock')

    bld.stlib(source='OcrAccount.cpp OcrAccountStreamReader.cpp OcrDigit.cpp',
              target='ocr')

    bld.add_post_fun(waf_unit_test.summary)
