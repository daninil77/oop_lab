// Четырёхбитный сдвиговый регистр влево 
module shift_reg_left_4(clk, en, ISL, rst, OSL, shift_rg);
	input clk;
	input en;
	input ISL;
	input rst;
	output reg OSL;
	output reg [3:0] shift_rg;

	initial shift_rg = 4'b0;
	
	always @(posedge clk) begin
		if (rst) begin
			shift_rg <= 4'b0; // сброс в 0
			OSL <= 1'b0; // выходной (старший) бит - 0
		end else begin
			if (en) begin
				shift_rg <= {shift_rg[2:0], ISL}; // сдвиг влево на один бит
				OSL <= shift_rg[3]; // выходной (старший) бит
			end else begin
				OSL <= 1'b0; // выходной (старший) бит - 0
				shift_rg <= shift_rg; // хранение
			end
		end
	end

endmodule
