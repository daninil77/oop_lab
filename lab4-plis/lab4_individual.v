module lab4_individual(CLOCK_50, SW, KEY, LEDR, LEDG, HEX0, HEX1, HEX2, HEX3);

	input CLOCK_50;
	input [9:0]SW;
	input [3:0]KEY;
	
	output [9:0]LEDR;
	output [7:0]LEDG;
	output [6:0]HEX0;
	output [6:0]HEX1;
	output [6:0]HEX2;
	output [6:0]HEX3;
	
	// clk - сигнал синхронизации
	wire clk;
	assign clk = CLOCK_50;
	
	// погасим неиспользуемые семисегментные индикаторы
	assign HEX2 = {7{1'b1}};
	assign HEX3 = {7{1'b1}};
	
	// 10-ти разрядный сдвиговый регистр
	// значение регистра отображается на LEDR
	reg [9:0]shift_reg;
	initial shift_reg = 10'b0;
	assign LEDR = shift_reg;
	
	// 7-разрядный двоичный счётчик
	// значение счётчика отображается на семисегментных индикаторах
	reg [6:0]counter;
	initial counter =7'b0;
	wire [7:0]counter_bcd;
	bin2bcd(counter, counter_bcd);
	dec7_decoder(.x(counter_bcd[3:0]), .switch_on(1'b1), .hex(HEX0));
	dec7_decoder(.x(counter_bcd[7:4]), .switch_on(1'b1), .hex(HEX1));
	
	// KEY[1] - асинхронный сброс устройства
	wire rst;
	synchronizer(.clk(clk), .in(~KEY[1]), .out(rst));
	
	// синхронизируем сигнал нажатия клавиши KEY[0]
	wire press_shift_key0_signal;
	synchronizer(.clk(clk), .in(~KEY[0]), .out(press_shift_key0_signal));
	
	// реализация сдвигового регистра и счётчика
	reg [2:0]sum_6_0;
	always @(posedge press_shift_key0_signal or posedge rst)
	begin
		if (rst)
		begin
			shift_reg <= 10'b0;
			counter <= 7'b0;
		end else begin
			shift_reg = {shift_reg[8:0], SW[0]};
			
			// проверим выполнение условия и при его выполнении инкрементируем счётчик
			// условие: Сумма младших 7 разрядов больше 4
			sum_6_0 = shift_reg[0] + shift_reg[1] + shift_reg[2] + shift_reg[3] + shift_reg[4] + shift_reg[5] + shift_reg[6];
			if (sum_6_0 > 3'd4)
				counter = counter + 1;
			
		end
	end
	
endmodule
