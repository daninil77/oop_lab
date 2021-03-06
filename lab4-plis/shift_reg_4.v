// Четырёхбитный сдвиговый регистр с выбором направления сдвига
module shift_reg_4(clk, dir, en, ISb, rst, OSb, shift_rg);
	input clk;
	input dir;
	input en;
	input ISb;
	input rst;
	output reg OSb;
	output reg [3:0] shift_rg;

	initial shift_rg = 4'b0;
	
	always @(posedge clk or posedge rst) begin
	
		if (rst) begin // сброс
		
			shift_rg <= 4'b0; // сброс в 0
			OSb <= 1'b0; // выходной (старший) бит - 0
			
		end else begin
		
			if (en) begin // сдвиг
			
				if (dir) begin // сдвиг влево
					OSb <= shift_rg[3]; // выходной (старший) бит
					shift_rg <= {shift_rg[2:0], ISb}; // сдвиг влево на один бит
				end else begin // сдвиг вправо
					OSb <= shift_rg[0]; // выходной (младший) бит
					shift_rg <= {ISb, shift_rg[2:0]}; // сдвиг вправо на один бит
				end
				
			end else begin // режим хранения
			
				OSb <= 1'b0; // выходной бит - 0
				shift_rg <= shift_rg; // хранение
				
			end
		end
		
	end

endmodule
