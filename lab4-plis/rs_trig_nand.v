// RS-триггер в базисе И-НЕ
module rs_trig_nand(nR, nS, Q, nQ);
	input nR;
	input nS;
	output Q;
	output nQ;
	
	assign Q = ~(nS & nQ);
	assign nQ = ~(nR & Q);
	
endmodule
