<?php

require_once('../mysqli_connect.php');


$query = "SELECT TypeId, TypeName FROM NoteTypes";

// Get a response from the database by sending the connection
// and the query
$response = @mysqli_query($dbc, $query);

// If the query executed properly proceed
if($response)
{

echo '<table align="left"
cellspacing="5" cellpadding="8">

<tr>
<td align="left"><b>TypeId</b></td>
<td align="left"><b>TypeName</b></td>
</tr>';

// mysqli_fetch_array will return a row of data from the query
// until no further data is available
while($row = mysqli_fetch_array($response)){

echo '<tr><td align="left">' . 
$row['TypeId'] . '</td><td align="left">' . 
$row['TypeName'] . '</td><td align="left">';

echo '</tr>';
}

echo '</table>';

} else {

echo "Couldn't issue database query<br />";

echo mysqli_error($dbc);

}

// Close connection to the database
mysqli_close($dbc);

?>