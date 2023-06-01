#include "QueryResult.hpp"

QueryResult::ResultIter QueryResult::begin() const
{
    return lines->begin();
}

QueryResult::ResultIter QueryResult::end() const
{
    return lines->end();
}

const StrBlob &QueryResult::get_file() const
{
    return file;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << "\'" << qr.sought << "\' occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.")
       << std::endl;

    for (auto num : *(qr.lines))
    {
        auto p = ConstStrBlobPtr(qr.file, num - 1);
        os << "\t(line " << num << ") " << p.deref() << std::endl;
    }

    return os;
}

std::ostream &print(std::ostream &os, const QueryResult &qr, TextQuery::line_no head, TextQuery::line_no tail)
{
    if (head > tail)
    {
        os << "Illegal range!" << std::endl;
        return os;
    }
    else
    {
        os << "\'" << qr.sought << "\' occurs " << qr.lines->size() << ((qr.lines->size() > 1) ? " times." : " time.")
           << " Display range: " << head << "-" << tail << std::endl;

        for (auto num : *(qr.lines))
        {
            if (head <= num && num <= tail)
            {
                auto p = ConstStrBlobPtr(qr.file, num - 1);
                os << "\t(line " << num << ") " << p.deref() << std::endl;
            }
        }
        return os;
    }
}
