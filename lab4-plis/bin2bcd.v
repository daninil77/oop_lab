module bin2bcd(bin, bcd);
	input [6:0]bin;
	output[7:0]bcd;
	
	// bcd[3:0] = bin % 10
	// bcd[7:4] = bin / 10
	
	reg [3:0]bin_div10;
	reg [6:0]bin_div10_mul10;
	
	always @(bin)
	begin
	
		if (bin < 7'd10) begin
			bin_div10 <= 4'd0;
			bin_div10_mul10 <= 7'd0;
		end else if (bin < 7'd20) begin
			bin_div10 <= 4'd1;
			bin_div10_mul10 <= 7'd10;
		end else if (bin < 7'd30) begin
			bin_div10 <= 4'd2;
			bin_div10_mul10 <= 7'd20;
		end else if (bin < 7'd40) begin
			bin_div10 <= 4'd3;
			bin_div10_mul10 <= 7'd30;
		end else if (bin < 7'd50) begin
			bin_div10 <= 4'd4;
			bin_div10_mul10 <= 7'd40;
		end else if (bin < 7'd60) begin
			bin_div10 <= 4'd5;
			bin_div10_mul10 <= 7'd50;
		end else if (bin < 7'd70) begin
			bin_div10 <= 4'd6;
			bin_div10_mul10 <= 7'd60;
		end else if (bin < 7'd80) begin
			bin_div10 <= 4'd7;
			bin_div10_mul10 <= 7'd70;
		end else if (bin < 7'd90) begin
			bin_div10 <= 4'd8;
			bin_div10_mul10 <= 7'd80;
		end else if (bin < 7'd100) begin
			bin_div10 <= 4'd9;
			bin_div10_mul10 <= 7'd90;
		end else begin
			// выведем ошибку (EE)
			bin_div10 <= 4'hE;
			bin_div10_mul10 <= bin - 7'hE;
		end
	
	end
	
	// bcd[3:0] = bin % 10
	wire [6:0]bin_mod10;
	assign bin_mod10 = bin - bin_div10_mul10;
	assign bcd[3:0] = bin_mod10[3:0];
	
	// bcd[7:4] = bin / 10
	assign bcd[7:4] = bin_div10;

endmodule
