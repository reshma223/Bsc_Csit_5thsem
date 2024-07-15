<?php
function customErrorHandler($errno, $errstr, $errfile, $errline) {
    throw new ErrorException($errstr, 0, $errno, $errfile, $errline);
}

// Set the custom error handler
set_error_handler("customErrorHandler");

try {
    // Division operation
    $numerator = 10;
    $denominator = 0;

    // Attempting division
    $result = $numerator / $denominator;

    // This line won't be executed if an exception is thrown
    echo "Result: $result";
} catch (ErrorException $e) {
    // Handling the exception
    echo "Error: " . $e->getMessage();
}

// Restoring the default error handler
restore_error_handler();
?>
