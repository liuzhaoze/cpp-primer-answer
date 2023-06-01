#include "TextQuery.hpp"
#include "../../../lib/strip.hpp"
#include "QueryResult.hpp"
#include <fstream>
#include <sstream>

TextQuery::TextQuery(std::ifstream &infile)
{
    std::string line;

    while (std::getline(infile, line))
    {
        file.push_back(line);

        int n = file.size();
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            auto &exist_lines = wm[strip(word)];

            if (!exist_lines)
            {
                exist_lines.reset(new std::set<line_no>);
            }
            exist_lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(strip(sought));

    if (loc == wm.end())
    {
        return QueryResult(sought, nodata, file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}
