// Дешифратор для вывода десятичных цифр на семисегментный индикатор
module dec7_decoder(input [3:0]x, input switch_on, output reg [6:0]hex);
	always @ *
	begin
		
		/* Включение / выключение индикатора */
		if (switch_on) begin
			
			/* Дешифратор для семисигментного индикатора */
			case(x)
			/* 0 - 3 */
				4'b0000: hex <= 7'b1000000;
				4'b0001: hex <= 7'b1111001;
				4'b0010: hex <= 7'b0100100;
				4'b0011: hex <= 7'b0110000;
			/* 4 - 7 */
				4'b0100: hex <= 7'b0011001;
				4'b0101: hex <= 7'b0010010;
				4'b0110: hex <= 7'b0000010;
				4'b0111: hex <= 7'b1111000;
			/* 8 - 9 */
				4'b1000: hex <= 7'b0000000;
				4'b1001: hex <= 7'b0010000;
			
			/* Default: show E (error) */
				default: hex <= 7'b0000110;
			endcase
		
		end else hex <= {7{1'b1}};
		
	end
endmodule
