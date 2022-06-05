// Защёлка D-типа (асинхронный D-триггер)
module d_latch(d, en, q);
	input d;
	input en;
	output reg q;

	always @(en, d) begin
		if (en) q <= d; // запись
		else q<= q; // хранение
	end

endmodule
