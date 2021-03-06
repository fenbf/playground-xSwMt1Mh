# 5 eays unique_ptr



@[auto_ptr fail]({"stubs": ["cpp_autoptr_fail.cpp"],"command": "sh ./run.sh cpp_autoptr_fail.cpp"})

@[pimpl]({"stubs": ["cpp_pimpl.h", "cpp_pimpl.cpp", "cpp_pimpl_client.cpp"],"command": "sh ./run_two.sh cpp_pimpl.cpp cpp_pimpl_client.cpp"})

@[unique_ptr in functions]({"stubs": ["cpp_unique_ptr_func.cpp"],"command": "sh ./run.sh cpp_unique_ptr_func.cpp"})

@[unique_ptr custom deleter]({"stubs": ["cpp_unique_ptr_custom.cpp", "cpp_unique_ptr_custom.h"],"command": "sh ./run.sh cpp_unique_ptr_custom.cpp"})

@[Improved pimpl]({"stubs": ["cpp_pimpl2.h", "cpp_pimpl2.cpp", "cpp_pimpl2_client.cpp"],"command": "sh ./run_two.sh cpp_pimpl2.cpp cpp_pimpl2_client.cpp"})

@[Propagate const]({"stubs": ["cpp_propagate_const.cpp"],"command": "sh ./run.sh cpp_propagate_const.cpp"})


### Call to action:

This playground is adapted from my blog: [Bartek's coding blog: Enforcing code contracts with nodiscard](http://www.bfilipek.com/2017/11/nodiscard.html)

Visit the blog if you're looking for more good stuff about C++ :)

