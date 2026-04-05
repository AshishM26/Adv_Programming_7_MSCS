(* 
   This program demonstrates functional programming in OCaml.
   The dataset is immutable, and the solution uses list transformations,
   recursion, and higher-order functions instead of imperative loops.
*)

let data = [12; 6; 3; 6; 9; 15; 6; 3; 12]

let string_of_int_list values =
  "[" ^ String.concat ", " (List.map string_of_int values) ^ "]"

let calculate_mean values =
  (*
     Functional style is visible here because List.fold_left reduces
     the list to a single sum without mutating the original dataset.
  *)
  let sum = List.fold_left ( + ) 0 values in
  float_of_int sum /. float_of_int (List.length values)

let calculate_median values =
  (*
     Immutability is preserved because List.sort returns a new sorted list
     rather than changing the original dataset in place.
  *)
  let sorted = List.sort compare values in
  let length = List.length sorted in
  if length mod 2 = 0 then
    let left = List.nth sorted (length / 2 - 1) in
    let right = List.nth sorted (length / 2) in
    float_of_int (left + right) /. 2.0
  else
    float_of_int (List.nth sorted (length / 2))

let calculate_mode values =
  let sorted = List.sort compare values in

  (*
     The mode is derived from a sorted list by grouping repeated values.
     This recursive helper walks through the list without mutable references,
     which keeps the implementation functional and beginner-friendly.
  *)
  let rec build_counts current_value current_count remaining counts =
    match remaining with
    | [] -> List.rev ((current_value, current_count) :: counts)
    | head :: tail ->
        if head = current_value then
          build_counts current_value (current_count + 1) tail counts
        else
          build_counts head 1 tail ((current_value, current_count) :: counts)
  in

  let counts =
    match sorted with
    | [] -> []
    | head :: tail -> build_counts head 1 tail []
  in

  let highest_count =
    List.fold_left (fun best (_, count) -> max best count) 0 counts
  in

  counts
  |> List.filter (fun (_, count) -> count = highest_count)
  |> List.map fst

let () =
  let mean = calculate_mean data in
  let median = calculate_median data in
  let modes = calculate_mode data in

  print_endline "========================================";
  print_endline "Statistics Calculator Demo";
  print_endline "========================================";
  print_endline ("Data: " ^ string_of_int_list data);
  Printf.printf "Mean: %.2f\n" mean;
  Printf.printf "Median: %.2f\n" median;
  print_endline ("Mode(s): " ^ string_of_int_list modes)
