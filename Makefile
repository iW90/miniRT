minilib:
	git clone https://github.com/codam-coding-college/MLX42.git
	cd MLX42 && \
	sed -i 's/3.18.0/3.16.0/' CMakeLists.txt && \
	cmake -B build && \
	cmake --build build -j4 && mv build/libmlx42.a .. && \
	cd .. && \
	rm -rf MLX42
