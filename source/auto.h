#pragma once

#include "basic.h"
#include <filesystem>

cardname cid2cn(std::string s);

state autoRead(std::string _s, int& _tar, int& countsLimit);

namespace fs = std::filesystem;

// �ڸ���Ŀ¼Ѱ�����µ���־Ŀ¼�������ֵ���
fs::path findNewestDirectory(const std::string& installationPath);
