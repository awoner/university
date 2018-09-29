{@ foreach ($data as $student): @}
<h2>{{$student['name']}}</h2>
<p>{{$student['surname'] . " " . $student['patronymic']}}</p>
<p>{{$student['birth_date']}}</p>
<p>{{$student['fp_name'] . " " . $student['exam_name']}}</p>
{@ endforeach; @}