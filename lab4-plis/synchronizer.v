// Схема формирования синхронного сигнала из асинхронного сигнала события
module synchronizer(clk, in, out);
	input clk;
	input in;
	output out;
	
	// выходы D-триггеров в схеме синхронизации
	reg q0;
	reg q1;
	reg q2;
	
	// реализация D-триггеров
	always @(posedge clk)
	begin
		q0 <= in;
		q1 <= q0;
		q2 <= q1;
	end
	
	assign out = q1 & (~q2);

endmodule
