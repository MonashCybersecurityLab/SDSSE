#include "Core/SSEClientHandler.h"

int main() {
    SSEClientHandler client;

//    cout << duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() << endl;
    for (int i = 0; i < 200; ++i) {
        client.update(INS, "test", i, (uint8_t*) &i, sizeof(i));
    }
//    cout << duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() << endl;
    for (int i = 0; i < 10; ++i) {
        client.update(DEL, "test", i, (uint8_t*) &i, sizeof(i));
    }

    vector<string> results = client.search("test");
    for (const string& res : results) {
        cout << *((int*) res.c_str()) << endl;
    }
    return 0;
}