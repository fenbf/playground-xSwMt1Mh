#include <memory>
#include <iostream>

#include "cpp_unique_ptr_custom.h"

int main()
{
    ModernWordCache myModernClass;
    ModernWordCache::unique_legacylist_ptr pUniqueList(new LegacyList());
    
    myModernClass.UpdateCache(std::move(pUniqueList));
}