#include "SearchResultCollection.h"

template<class T>
void SearchResultCollection<T>::add(T singleResult) {
    this->data.push_back(singleResult);
}

template<class T>
void SearchResultCollection<T>::display() {
    if (this->data.empty()) {
        cout << "No results!" << endl;
        return;
    }

    cout << "Files that matches to requested search query:" << endl;
    for (const auto &resultEntity: this->data) {
        cout << (string) resultEntity << endl;
    }
}
