<?php

function value_to_string($value) {
    if (is_null($value)) {
        return 'NULL';
    } else if ($value === true) {
        return 'TRUE';
    } else if ($value === FALSE) {
        return 'FALSE';
    } else if (is_array($value)) {
        return 'ARRAY';
    } else if (is_numeric($value)) {
        return "NUMERIC ($value)";
    } else if (is_string($value)) {
        return "STRING ($value)";
    }
}

function test_ifnull($value, $value_if_null) {
    $r = ifnull($value, $value_if_null);
    if ($r === $value_if_null) {
        printf(" > '%s' is NULL\n", value_to_string($value));
    } else {
        printf(" > '%s' is NOT NULL\n", value_to_string($value));
    }
}

function test_ifempty($value, $value_if_empty) {
    $r = ifempty($value, $value_if_empty);
    if ($r === $value_if_empty) {
        printf(" > '%s' is EMPTY\n", value_to_string($value));
    } else {
        printf(" > '%s' is NOT EMPTY\n", value_to_string($value));
    }
}

function test() {
    $values = array(null, 'NOT NULL', '', 0, 0.0, 1, true, false, array());

    echo "--- Testing ifnull() ---\n";
    foreach ($values as $value) {
        test_ifnull($value, 'VALUE_IF_NULL');
    }

    echo "\n--- Testing ifempty() ---\n";
    foreach ($values as $value) {
        test_ifempty($value, 'VALUE_IF_EMPTY');
    }
}

test();
