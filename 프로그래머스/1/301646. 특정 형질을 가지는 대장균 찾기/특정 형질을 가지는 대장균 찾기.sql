select count(*) as 'COUNT' from ECOLI_DATA 
where (genotype & 2) = 0 
AND ((genotype & 1) > 0 or (genotype & 4) > 0);