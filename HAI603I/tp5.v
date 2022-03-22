Require Import Arith.
Require Import Omega.
Require Export List.
Open Scope list_scope.
Import ListNotations.
Require Import FunInd. 

Inductive is_sorted : list nat ->  Prop :=
 | is_sorted_nil : is_sorted nil
 | is_sorted_un : forall e : nat, is_sorted (e::nil)
 | is_sorted_S : forall e : nat, forall h : nat, forall q : list nat, e<=h -> is_sorted(h::q) -> is_sorted(e::h::q).

Inductive is_perm : list nat -> list nat -> Prop :=
 | is_perm_reflex : forall l : list nat, is_perm l l
 | is_perm_S : forall e : nat, forall l l' : list nat, is_perm l l' -> is_perm (e::l) (e::l')
 | is_perm_S_app : forall e : nat, forall l l' : list nat, is_perm l l' -> is_perm (e::l) (l'++(e::nil))
 | is_perm_sym : forall l l' : list nat, is_perm l l' -> is_perm l' l
 | is_perm_trans : forall l1 l2 l3 : list nat, is_perm l1 l2 -> is_perm l2 l3 -> is_perm l1 l3.


Fixpoint sort (l : list nat) {struct l} : list nat :=
 match l with
 | nil => nil
 | (a :: nil) => a :: nil 
 | (a :: l) => app (sort l) (a :: nil)
 end. 

Lemma x2 : is_sorted [1; 2; 3].
Proof.
 apply is_sorted_S.
 auto.
 apply is_sorted_S. 
 auto.
 apply is_sorted_un.
Qed.



