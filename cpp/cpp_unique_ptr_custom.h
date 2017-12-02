#include <memory>
#include <iostream>

// This class cannot be changed, might come from 3rd party library
// to delete it completely you need to call ReleaseElements first!
class LegacyList {
public:
    void Add(const std::string& str ) { }
    void Remove(const std::string& str ) { }
    
    void ReleaseElements() { }
};

// stateless functor
struct LegacyListDeleterFunctor {  
    void operator()(LegacyList* p) {
        p->ReleaseElements(); 
        delete p;
        std::cout << "LegacyListDeleterFunctor..." << std::endl;
    }
};

// Modern version of the cache, we use std::unique_ptr with custom deleter to handle deletion of LegacyList
// we can remove default constructor and destructor, since unique_ptr will do this for us
// also we could remove ClearCache method (since it was only for conveniance)
class ModernWordCache {
public:
    using unique_legacylist_ptr_functor = std::unique_ptr<LegacyList, LegacyListDeleterFunctor>; 
    
    using unique_legacylist_ptr = unique_legacylist_ptr_functor;
public:
    void UpdateCache(unique_legacylist_ptr pInputList) { 
        m_pList = std::move(pInputList);
        // do something with the list...
    }

private:
    //unique_legacylist_ptr m_pList { nullptr, &DeleteLegacyList };
    unique_legacylist_ptr m_pList;
};