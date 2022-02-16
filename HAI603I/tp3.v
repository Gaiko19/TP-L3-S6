Fixpoint mult (m n :nat) {struct m} : nat :=
  match m with 
    | 0 => 0
    | S p => (plus (mult p n) n)
  end.

Theorem ex1_2 : forall n : nat, mult 2 n = plus n n.
Proof.
 intro.
 simpl.
 reflexivity.
Qed.

Lemma David : forall m n : nat, plus m (S n) = S (plus m n).
Proof.
 intros.
 elim m.
 simpl.
 reflexivity. 
 intros.
 simpl.
 rewrite H.
 reflexivity.
Qed.

Lemma comPlus : forall m n : nat, plus m n = plus n m.
Proof.
 intros.
 elim m.
 elim n.
 reflexivity.

 intros.
 simpl.
 rewrite <- H.
 simpl.
 reflexivity.

 intros.
 simpl.
 rewrite H.
 rewrite David.
 reflexivity.
Qed.

Theorem ex1_3 : forall n : nat, mult n 2 = plus n n. 
Proof.
 intro.
 elim n.
 simpl.
 reflexivity.
 
 intros.
 simpl.
 rewrite H.
 rewrite comPlus.
 simpl.
 rewrite (comPlus n0 (S n0)).
 simpl.
 reflexivity.
Qed.

Open Scope list.

Parameter E : Type.

Fixpoint rev (l : list E) {struct l} : list E :=
 match l with
  | nil => nil
  | e::q => (rev q) ++ (e::nil)
 end.

Theorem ex2_2 : forall l : list E, forall e : E, rev(l ++ (e::nil)) = e::rev(l). 
Proof.
 intros.
 elim l.
 simpl.
 reflexivity.

 intros.
 simpl.
 rewrite H.
 reflexivity.
Qed.

Parameter S : Set.

Inductive FProp : Set :=
 | Symb : S -> FProp
 | Not : FProp -> FProp 
 | And : FProp -> FProp -> FProp
 | Or : FProp -> FProp -> FProp
 | Impl : FProp -> FProp -> FProp
 | Equ : FProp -> FProp -> FProp.

Parameter a b c : S.

Check (Symb a).

Check (Not (And (Symb a) (Symb b))).

Fixpoint sub (f : FProp) {struct f} : list FProp :=
 match f with 
  | (Symb s) => s::nil
  | (Not g) => (Not g)::(subg)
  | (And g h) => (sub g) ++ (sub h)










