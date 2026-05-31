#pragma once

#include <string>
#include <unordered_map>

namespace RoguelikeGame
{
	using Record = std::pair<std::string, int>;
	using RecordsMap = std::unordered_map<std::string, int>;
	using RecordsVector = std::vector<std::pair<std::string, int>>;
}