#include "Query.hpp"
#include "QueryHistory.hpp"
#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void runQuery(const Query &q, const TextQuery &tq)
{
    std::cout << "Executing Query for: " << q.rep() << std::endl;

    auto result = q.eval(tq);
    print(std::cout, result) << std::endl;
}

int main()
{
    std::ifstream infile("../../data/storyDataFile");
    TextQuery tq(infile);

#ifdef DEBUG
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << std::string(40, '=') << std::endl;
    std::cout << q.rep() << std::endl;
#else
    Query q1 = Query("daddy");
    Query q2 = ~Query("Alice");
    Query q3 = Query("hair") | Query("Alice");
    Query q4 = Query("hair") & Query("Alice");
    Query q5 = Query("fiery") & Query("bird") | Query("wind");
    std::vector<Query> vec{q1, q2, q3, q4, q5};

    for (const auto &q : vec)
    {
        runQuery(q, tq);
    }

    // quiz_15.42 (b)
    QueryHistory history;
    history.add_query(q1);
    history.add_query(q5);
    runQuery(history[0] & history[1], tq);

    // quiz_15.42 (c)
    print(std::cout, q2.eval(tq), 5, 7) << std::endl;
#endif

    return 0;
}
