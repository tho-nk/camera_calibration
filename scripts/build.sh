export project_name=bilberry

cd ${project_name}

cmake -B build .
make -C build -j${nproc}