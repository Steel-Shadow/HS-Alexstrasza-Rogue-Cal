#pragma once

#include "basic.h"
#include <filesystem>

cardname cid2cn(const std::string &s);

state autoRead(std::string _s, int& _tar, int& countsLimit);

namespace fs = std::filesystem;

// 在给定目录寻找最新的日志目录（依照字典序）
fs::path findNewestDirectory(const std::string& installationPath);
