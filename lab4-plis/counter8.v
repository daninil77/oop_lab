// Восьмибитный счётчик
module counter8(clk, en, rst, counter);
	input clk;
	input en;
	input rst;
	output reg [7:0] counter;
	
	// в начальный момент времени счётчик сброшен в 0
	initial counter = 8'b0;

	always @(posedge clk or posedge rst) begin
		if (rst) counter <= 0; // сброс в 0
		else begin
			if (en) counter <= counter + 1; // счёт
			else counter <= counter; // хранение
		end
	end

endmodule
