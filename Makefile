all: frequency_table decode copyrecords 

copyrecords: copyrecords.o add_letters.o create_freq_table.o letter_count.o encode.o chi_sq.o offset.o rot_any.o encode_shift.o decode_shift.o file_size.o read_char.o tflag.o Xflag.o
	gcc -ansi -Wall -o copyrecords copyrecords.o add_letters.o create_freq_table.o letter_count.o encode.o chi_sq.o offset.o rot_any.o encode_shift.o decode_shift.o file_size.o read_char.o tflag.o Xflag.o

decode: decode.o add_letters.o create_freq_table.o letter_count.o encode.o chi_sq.o offset.o rot_any.o encode_shift.o decode_shift.o file_size.o read_char.o tflag.o Xflag.o
	gcc -ansi -Wall -o decode decode.o add_letters.o create_freq_table.o letter_count.o encode.o chi_sq.o offset.o rot_any.o encode_shift.o decode_shift.o file_size.o read_char.o tflag.o Xflag.o

frequency_table: frequency_table.o add_letters.o create_freq_table.o letter_count.o
	gcc -ansi -Wall -o frequency_table frequency_table.o add_letters.o create_freq_table.o letter_count.o

frequency_table.o: frequency_table.c
	gcc -ansi -Wall -c frequency_table.c

add_letters.o: add_letters.c
	gcc -ansi -Wall -c add_letters.c

create_freq_table.o: create_freq_table.c 
	gcc -ansi -Wall -c create_freq_table.c

letter_count.o: letter_count.c 
	gcc -ansi -Wall -c letter_count.c 

encode.o: encode.c
	gcc -ansi -Wall -c encode.c 

chi_sq.o: chi_sq.c 
	gcc -ansi -Wall -c chi_sq.c 

offset.o: offset.c 
	gcc -ansi -Wall -c offset.c 

encode_shift.o: encode_shift.c 
	gcc -ansi -Wall -c encode_shift.c 

decode_shift.o: decode_shift.c 
	gcc -ansi -Wall -c decode_shift.c 

rot_any.o: rot_any.c 
	gcc -ansi -Wall -c rot_any.c 

decode.o: decode.c
	gcc -ansi -Wall -c decode.c

file_size.o: file_size.c 
	gcc -ansi -Wall -c file_size.c

read_char.o: read_char.c 
	gcc -ansi -Wall -c read_char.c 	

tflag.o: tflag.c 
	gcc -ansi -Wall -c tflag.c 

Xflag.o: Xflag.c 
	gcc -ansi -Wall -c Xflag.c 

copyrecords.o: copyrecords.c 
	gcc -ansi -Wall -c copyrecords.c 

clean: 
	rm copyrecords frequency_table decode frequency_table.o letter_count.o create_freq_table.o add_letters.o encode.o chi_sq.o offset.o encode_shift.o decode_shift.o decode.o file_size.o read_char.o rot_any.o tflag.o Xflag.o copyrecords.o 