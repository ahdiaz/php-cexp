<?php

function test_ifnull($value, $null_value) {
	$r = ifnull($value, $null_value);
	var_dump($value);
	echo ">>\n";
	var_dump($r);
	echo "\n";
}

function test_ifempty($value, $null_value) {
	$r = ifempty($value, $null_value);
	var_dump($value);
	echo ">>\n";
	var_dump($r);
	echo "\n";
}

$values = array(null, 'NOT NULL', '', 0, 0.0, true, false, array());
$is_null = 'is null';
$is_empty = 'is empty';

echo "--- ifnull() ---\n";
foreach ($values as $value) {
	test_ifnull($value, $is_null);
}

echo "--- ifempty() ---\n";
foreach ($values as $value) {
	test_ifempty($value, $is_empty);
}

