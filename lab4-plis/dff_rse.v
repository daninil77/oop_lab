// D-триггер (синхронный)
module dff_rse(d, clk, set, rst, en, q);
	input d;
	input clk;
	input set;
	input rst;
	input en;
	output reg q;

	always @(posedge clk or posedge set or posedge rst ) begin
		if (set)
			q <= 1'b1; // установка в 1
		else begin
			if (rst) q <= 1'b0; // сброс в 0
			else begin
				if (en) q <= d; // запись
				else q <= q; // хранение
			end
		end
	end
	
endmodule
