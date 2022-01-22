/*
    Copyright (c) 2016-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_TESTS_CORE_CONSOLEAPPLICATIONTEST_HPP_
#define _ISHIKO_CPP_TESTS_CORE_CONSOLEAPPLICATIONTEST_HPP_

#include "Test.hpp"
#include "FileComparisonTest.hpp"
#include <string>

namespace Ishiko
{
namespace Tests
{

class ConsoleApplicationTest : public Test
{
public:
    ConsoleApplicationTest(const TestNumber& number, const std::string& name, const std::string& commandLine,
        int expectedExitCode);
    ConsoleApplicationTest(const TestNumber& number, const std::string& name, const std::string& commandLine,
        int expectedExitCode, const TestContext& context);
    
    void setStandardOutputFilePath(const boost::filesystem::path& path);
    void setStandardOutputReferenceFilePath(const boost::filesystem::path& path);

protected:
    void doRun() override;

private:
    std::string m_commandLine;
    bool m_checkExitCode;
    int m_expectedExitCode;
    FileComparisonTest m_standardOutputTest;
};

}
}

#endif
