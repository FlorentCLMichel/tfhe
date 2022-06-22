file(REMOVE_RECURSE
  "libtfhe-graphec.pdb"
  "libtfhe-graphec.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/tfhe-graphec.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
