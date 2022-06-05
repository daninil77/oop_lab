// Восьмибитный регистр
module register8(d, clk, rst, en, q);
	input [7:0] d;
	input clk;
	input rst;
	input en;
	output reg [7:0]q;
	
	// в начальный момент времени в регистре хранится 0
	initial q <= 8'b0;

	always @(posedge clk or posedge rst) begin
		if (rst) q <= 7'b0; // сброс с 0
		else begin
			if (en) q <= d; // запмсь
			else q <= q; // хранение
		end
	end

endmodule
