main(n){for(;~scanf("%d",&n);)puts(
	n<0?"This program is for humans":
	n<3?"Home":
	n<5?"Preschool":
	n<12?"Elementary school":
	n<15?"Middle school":
	n<19?"High school":
	n<23?"College":
	n<66?"Work":
	n<101?"Retirement":"This program is for humans"
);}