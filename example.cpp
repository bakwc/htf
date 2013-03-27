#include <iostream>
#include "fetcher.hpp"

using namespace std;

int main()
{
    { // Simple example
        string data;
        try {
            data = htf::GetUrl("http://example.com");
        } catch (const htf::TException& e) {
            cout << "Fetching failed: " << e.what() << "\n";
        }
        cout << data << "\n";
    }

    { // Custom headers & response example
        htf::THeaders headers;
        headers["User-Agent"] = "Mozilla/5.0 (htf)";
        htf::TResult res = htf::Fetch("http://example.com", headers, 10);
        cout << "Response code: " << res.Code << "\n";
        cout << "Response data: " << res.Content << "\n";
    }
    return 0;
}

