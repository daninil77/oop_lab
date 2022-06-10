onerror {quit -f}
vlib work
vlog -work work Lab5.vo
vlog -work work Lab5.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.secundomer_vlg_vec_tst
vcd file -direction Lab5.msim.vcd
vcd add -internal secundomer_vlg_vec_tst/*
vcd add -internal secundomer_vlg_vec_tst/i1/*
add wave /*
run -all
